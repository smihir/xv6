#include "types.h"
#include "user.h"

#define PGSIZE 4096
int
main(int argc, char *argv[])
{
  int *p, *q;
  int i;

  p = malloc(PGSIZE * sizeof(int));
  q = malloc(5 * sizeof(int));

  if (p == NULL) {
    printf(1, "malloc failed\n");
    exit();
  }

  for(i = 0; i < PGSIZE; i++) {
    //write to heap
    p[i] = i*10;

    if (i < 5)
      q[i] = i;
  }

  for(i = 0; i < PGSIZE; i += 500) {
    //read from heap
    printf(1, "heap val at index %d is %d\n",i, p[i]);
  }

  printf(1, "\n");

  for(i = 0; i < 5; i++) {
    //read from heap
    printf(1, "heap val at index %d is %d\n",i, q[i]);
  }
  exit();
}
