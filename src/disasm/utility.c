#include "utility.h"

void *local_malloc(size_t size) {
  if (size <= 0) {
    return NULL;
  }
  void *mem = malloc(size);
  if (mem != NULL) {
    local_memzero(mem, size);
  }
  return mem;
}

void local_free(void *addr) {
  if (addr != NULL) {
    free(addr);
  }
}

void local_memzero(void *addr, size_t size) {
  if (addr != NULL && size > 0) {
    memset(addr, 0, size);
  }
}
