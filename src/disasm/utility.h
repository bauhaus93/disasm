#ifndef UTILITY_H
#define UTILITY_H

#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

void *local_malloc(size_t size);
void local_free(void *addr);
void local_memzero(void *addr, size_t size);

#ifdef __cplusplus
}
#endif

#define OFFSET_ADDR(addr, offset) addr = (void*)(((int8_t*)addr) + offset)

#endif // UTILITY_H
