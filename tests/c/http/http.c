#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#define PORT "8080"
#define BACKLOG 1
#define REQ_BUF_SIZE 4096

int main(void) {
  WSADATA wsaData;
  struct addrinfo hints, *result = NULL;
  SOCKET listenSock = INVALID_SOCKET, clientSock = INVALID_SOCKET;
  int iResult;

  if ((iResult = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0) {
    printf("WSAStartup failed: %d\n", iResult);
    return 1;
  }

  ZeroMemory(&hints, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;
  hints.ai_flags = AI_PASSIVE;

  if ((iResult = getaddrinfo(NULL, PORT, &hints, &result)) != 0) {
    printf("getaddrinfo failed: %d\n", iResult);
    WSACleanup();
    return 1;
  }

  listenSock =
      socket(result->ai_family, result->ai_socktype, result->ai_protocol);
  if (listenSock == INVALID_SOCKET) {
    printf("socket failed: %d\n", WSAGetLastError());
    freeaddrinfo(result);
    WSACleanup();
    return 1;
  }

  if ((iResult = bind(listenSock, result->ai_addr, (int)result->ai_addrlen)) ==
      SOCKET_ERROR) {
    printf("bind failed: %d\n", WSAGetLastError());
    freeaddrinfo(result);
    closesocket(listenSock);
    WSACleanup();
    return 1;
  }
  freeaddrinfo(result);

  if ((iResult = listen(listenSock, BACKLOG)) == SOCKET_ERROR) {
    printf("listen failed: %d\n", WSAGetLastError());
    closesocket(listenSock);
    WSACleanup();
    return 1;
  }

  printf("HTTP server listening on port %s (one connection)...\n", PORT);

  clientSock = accept(listenSock, NULL, NULL);
  if (clientSock == INVALID_SOCKET) {
    printf("accept failed: %d\n", WSAGetLastError());
    closesocket(listenSock);
    WSACleanup();
    return 1;
  }

  char req_buf[REQ_BUF_SIZE];
  ZeroMemory(req_buf, sizeof(req_buf));
  iResult = recv(clientSock, req_buf, REQ_BUF_SIZE - 1, 0);
  if (iResult > 0) {
    req_buf[iResult] = '\0';

    char *hdr_end = strstr(req_buf, "\r\n\r\n");
    if (hdr_end) {
      int header_len = (int)((hdr_end + 4) - req_buf);

      char *cl_hdr = strstr(req_buf, "Content-Length:");
      if (cl_hdr) {
        int content_length = atoi(cl_hdr + strlen("Content-Length:"));
        printf("Received Content-Length = %d\n", content_length);

        char *body_buf = (char *)malloc(content_length);
        if (!body_buf) {
          printf("malloc failed\n");
        } else {
          // --- BUFFER OVERLOW ---
          int body_len = iResult - header_len;
          memcpy(body_buf, req_buf + header_len, body_len);

          printf("Received body (first 32B): %.32s\n", body_buf);

          free(body_buf);
        }
      }
    }
  } else {
    printf("recv failed or client closed connection\n");
  }

  const char *resp = "HTTP/1.1 200 OK\r\n"
                     "Content-Length: 2\r\n"
                     "Connection: close\r\n\r\n"
                     "OK";
  send(clientSock, resp, (int)strlen(resp), 0);

  closesocket(clientSock);
  closesocket(listenSock);
  WSACleanup();

  return 0;
}
