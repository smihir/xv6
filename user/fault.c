#include "types.h"
#include "user.h"
#include "param.h"

// bytes mapped by a page
#define PGSIZE 4096

int
main(int argc, char *argv[])
{
  char f[80];
  // some address between stack and heap
  char *fnull2 = (char *)(USERTOP - PGSIZE - sizeof(f));

  // Should crash here only, but I have put this here to address
  // boundary conditions bug

  if (fork() == 0) {
    char *fnull = (char *)(USERTOP - 2*PGSIZE - sizeof(f));
    printf(1, "value at fnull2: %c\n", *fnull);
    // If the above line is printed our test case has failed :(
  }

  printf(1, "value at fnull2: %c\n", *fnull2);
  // If the above line is printed our test case has failed :(
  exit();
}
