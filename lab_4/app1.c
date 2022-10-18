#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
  printf("APP1: %i\n", (int) getpid());
  printf("%s", "Hello world, imma app #1!\n");
  pause();
  return 0;
}
