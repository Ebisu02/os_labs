#include <dlfcn.h>

int main() {
  void* handle = dlopen("libworld.so", RTLD_LAZY);
  void (*lab_1)() = dlsym(handle, "lab_1");
  (*lab_1)();
  dlclose(handle);
}
