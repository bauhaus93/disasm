#include "prefix.h"

static PrefixList *append_prefix(Prefix prefix, PrefixList *curr);

// prefix_list must have space for 4 prefixes
PrefixList *get_prefixes(const void *addr) {
    if (addr == NULL) {
        return NULL;
    }
    uint8_t *ptr = (uint8_t *)addr;

    PrefixList *root = NULL;
    PrefixList *curr = root;

    int prefix_count = 0;
    uint8_t quit = 0;
    while (quit == 0 && prefix_count++ < 4) {
        switch (*ptr++) {
        case 0xF0:
            curr = append_prefix(LOCK, curr);
            break;
        case 0xF2:
            // can be REPNE _or_ BND
            // TODO: Check for BND
            curr = append_prefix(REPNE, curr);
            break;
        case 0xF3:
            curr = append_prefix(REPE, curr);
            break;
        case 0x2E:
            // can be override _or_ HINT_BRANCH_NOT_TAKEN (used in jcc
            // instructions)
            // TODO: check for HINT
            curr = append_prefix(SEG_OVERRIDE_CS, curr);
            break;
        case 0x36:
            curr = append_prefix(SEG_OVERRIDE_SS, curr);
            break;
        case 0x3E:
            // can be override _or_ HINT_BRANCH_TAKEN (used in jcc instructions)
            // TODO: check for HINT
            curr = append_prefix(SEG_OVERRIDE_DS, curr);
            break;
        case 0x26:
            curr = append_prefix(SEG_OVERRIDE_ES, curr);
            break;
        case 0x64:
            curr = append_prefix(SEG_OVERRIDE_FS, curr);
            break;
        case 0x65:
            curr = append_prefix(SEG_OVERRIDE_GS, curr);
            break;
        case 0x66:
            curr = append_prefix(OVERRIDE_OPERAND_SIZE, curr);
            break;
        case 0x67:
            curr = append_prefix(OVERRIDE_ADDRESS_SIZE, curr);
            break;
        default:
            quit = 1;
            break;
        }
        if (root == NULL && quit == 0) {
            root = curr;
        }
    }
    return root;
}

int count_prefixes(PrefixList* list) {
    if (list == NULL) {
        return 0;
    } else {
        return 1 + count_prefixes(list->next);
    }
}

void free_prefixes(PrefixList *list) {
    if (list == NULL) {
        return;
    }
    free_prefixes(list->next);
    local_free(list);
}

PrefixList *append_prefix(Prefix prefix, PrefixList *curr) {
    if (curr == NULL) {
        curr = (PrefixList *)local_malloc(sizeof(PrefixList));
        if (curr == NULL) {
            return NULL;
        }
        curr->value = prefix;
    } else {
        if (curr->next != NULL) {
            return NULL;
        }
        curr->next = (PrefixList *)local_malloc(sizeof(PrefixList));
        if (curr->next == NULL) {
            return NULL;
        }
        curr = curr->next;
        curr->value = prefix;
    }
    return curr;
}
