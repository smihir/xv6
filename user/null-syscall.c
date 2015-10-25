#include "types.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int fd;
  char f[80], *fnull = NULL;

  fd = open("README", O_RDONLY);

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
