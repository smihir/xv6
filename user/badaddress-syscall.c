#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "param.h"

// bytes mapped by a page
#define PGSIZE 4096
int
main(int argc, char *argv[])
{
  int fd;
  char f[80];
  // some address between stack and heap
  char *fnull = (char *)(USERTOP - PGSIZE - sizeof(f));

  fd = open("README", O_RDONLY);

  printf(1, "addr of f: %d addt of fnull: %d\n", f, fnull);
  if (fd == -1){
    printf(1, "error opening file\n");
    exit();
  }

  if (read(fd, f, sizeof(f)) == -1){
    printf(1, "error reading file into f\n");
    exit();
  }

  if (read(fd, fnull, 80) == -1){
    printf(1, "error reading file into fnull\n");
    exit();
  }
  exit();
}
