#include "lab_4.h"

int main() {
  printf("PROC: %i\n", (int) getpid());
  execl("/home/admin/os_labs/lab_4/app1", "");
  pause();
}
