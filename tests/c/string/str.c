#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void IRSENTRY_MOCK_NOPARAMS() { printf("TRAFIONY!\n"); }

int main(int argc, char **argv) {

  if (argc != 2) {
    printf("Usage: ./str.exe [req]");
    return 1;
  }

  const char *req_buf = argv[1];
  if (strstr(req_buf, "POST / HTTP/1.1\n") != req_buf) {
    return 1;
  }

  const char *hdr_start = req_buf + strlen("POST / HTTP/1.1\n");
  const char *hdr_end = strstr(hdr_start, "\n\n");
  if (strstr(hdr_start, "Content-Length:") == NULL) {
    return 1;
  }

  const char *p_cl = hdr_start + strlen("Content-Length:");
  int content_length = atoi(p_cl);

  const char *body = malloc(content_length);
  memcpy(body, hdr_end, content_length);

  if (content_length == 1234 && strstr(hdr_end + 4, "PARAM=1") != NULL) {
    IRSENTRY_MOCK_NOPARAMS();
  }

  return 0;
}
