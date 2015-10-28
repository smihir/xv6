#include "types.h"
#include "user.h"
#include "param.h"

#define PGSIZE 4096
int main() {
  char *b, *a;

  printf(1, "Go Go Go!\n");
  while(1) {
    b = malloc(sizeof(char) * PGSIZE);
    if(NULL == b){
      printf(1, "heap ptr: %x, heap ptr + PGSIZE %x, USERTOP - 2*PGSIZE %x\n",
             a, a + PGSIZE, USERTOP - 2*PGSIZE);
      break;
    }
    a = b;
  }

  exit();
}
