#include "types.h"
#include "user.h"
#include "param.h"

int stackbottom = USERTOP - 4096;
int fibonnacci(int n)
{
    if(n == 1 || n == 0){
        return n;
    }

    return fibonnacci(n-1) + fibonnacci(n-2);
}

// try to return n*m
int naivemult(int n, int m)
{
    int top;

    if ((int)(&top - sizeof(int)) < stackbottom) {
        printf(1, "stack was grown!\n");
        stackbottom -= 4096;
        printf(1, "new stack ends at %d\n", stackbottom);
    }
    if (m == 1){
        return n;
    }

    if (m == 0){
        return 1;
    }

    return naivemult(n, m-1) + n;
}

int
main(int argc, char *argv[])
{
  int n, m;
  int ne = 0;

  if (argc <= 2){
      printf(1, "not enough args, I will choose my own\n");
      ne = 1;
  }

  printf(1, "USERTOP is at %d, stack should end at %d\n",
             USERTOP, stackbottom);

  if(!ne){
    n = atoi(argv[1]);
    m = atoi(argv[2]);
  }else{
    n = 2;
    m = 155;
  }

  printf(1, "finding mult %d x %d\n", n, m);

  printf(1, "mult is %d\n", naivemult(n, m));
  exit();
}
