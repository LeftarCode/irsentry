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
  if (strstr(req_buf, "POST / HTTP/1.1@") != req_buf) {
    return 1;
  }

  const char *hdr_start = req_buf + strlen("POST / HTTP/1.1@");
  const char *cl_start = strstr(hdr_start, "Content-Length:");
  if (cl_start == NULL) {
    return 1;
  }

  const char *cl_num = cl_start + strlen("Content-Length:");
  if (atoi(cl_num) > 1234) {
    return 1;
  }

  IRSENTRY_MOCK_NOPARAMS();

  return 0;
}

// int main(int argc, char **argv) {
//
//   if (argc != 2) {
//     printf("Usage: ./str.exe [req]");
//     return 1;
//   }
//   if (strstr(argv[1], "bitwa") == NULL) {
//     return 1;
//   }
//   if (strstr(argv[1], "1410") == NULL) {
//     return 1;
//   }
//   IRSENTRY_MOCK_NOPARAMS();
//   return 0;
// }
