#ifndef PREFIX_H
#define PREFIX_H

#include <inttypes.h>
#include <stdlib.h>

#include "utility.h"

typedef enum {
    // group 1
    LOCK,
    REPNE,
    REPE,
    BND,
    // group 2
    SEG_OVERRIDE_CS,
    SEG_OVERRIDE_SS,
    SEG_OVERRIDE_DS,
    SEG_OVERRIDE_ES,
    SEG_OVERRIDE_FS,
    SEG_OVERRIDE_GS,
    HINT_BRANCH_NOT_TAKEN,
    HINT_BRANCH_TAKEN,
    // group 3
    OVERRIDE_OPERAND_SIZE,
    // group 4
    OVERRIDE_ADDRESS_SIZE
} Prefix;

typedef struct PrefixList_ {
    Prefix value;
    struct PrefixList_ *next;
} PrefixList;

#ifdef __cplusplus
extern "C" {
#endif

PrefixList *get_prefixes(const void *addr);
int count_prefixes(PrefixList* list);
void free_prefixes(PrefixList *list);

#ifdef __cplusplus
}
#endif

#endif // PREFIX_H
