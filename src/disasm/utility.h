#ifndef UTILITY_H
#define UTILITY_H

#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

void *local_malloc(size_t size);
void local_free(void *addr);
void local_memzero(void *addr, size_t size);

#ifdef __cplusplus
}
#endif

#endif // UTILITY_H
