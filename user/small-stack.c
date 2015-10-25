#include "types.h"
#include "user.h"
#include "param.h"

#define N 10
int
main(int argc, char *argv[])
{
  int a[N];
  int b[N]; //b will have addr less than a as stack grows upward
  int i;

  printf(1, "USERTOP is at %d, stack should start from %d\n",
             USERTOP, USERTOP - 4096);

  for(i = 0; i < N; i++){
      a[i] = i;
      b[i] = i;
  }
  for(i = 0; i < N; i++){
      printf(1, "addr of a[%d] -> %d, value %d\n", i, &a[i], a[i]);
  }
  printf(1, "\n");
  for(i = 0; i < N; i++){
      printf(1, "addr of b[%d] -> %d, value %d\n", i, &b[i], b[i]);
  }
  exit();
}
