#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int *p = NULL;
  printf(1, "%s", "p points to value: %d\n", *p);
  exit();
}
