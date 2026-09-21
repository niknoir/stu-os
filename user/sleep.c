#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
char buf[512];

void
cat(int fd)
{
  int n;

  while ((n = read(fd, buf, sizeof(buf))) > 0) {
    if (write(1, buf, n) != n) {
      fprintf(2, "sleep: write error\n");
      exit(1);
    }
  }
  if (n < 0) {
    fprintf(2, "sleep: read error\n");
    exit(1);
  }
}

int
main(int argc, char *argv[])
{
  int n = 0;
  int * pn = &n;
  if (argc < 1) {
    cat(0);
    exit(0);
  }
  for (int i = 0; i < argc; i++){
    n = atoi(argv[i]);
  }
  n *= 1000;
  wait(pn);
  fprintf(2, "time is: %d\n", n);

  exit(0);
}
