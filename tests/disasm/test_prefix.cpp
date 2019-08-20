#include <gtest/gtest.h>

#include "disasm/prefix.h"

TEST(Prefix, AddrNullExpectNull) {
    PrefixList *prefixes = get_prefixes(NULL);
    ASSERT_EQ(NULL, prefixes);
}

TEST(Prefix, NoPrefixesExpectNull) {
    uint8_t memory[] = {0, 0, 0, 0};
    PrefixList *prefix = get_prefixes((const void *)memory);
    ASSERT_EQ(NULL, prefix);
}

TEST(Prefix, OnePrefixCheck) {
    uint8_t memory[] = {0xF0, 0, 0, 0};
    PrefixList *prefix = get_prefixes((const void *)memory);
    ASSERT_NE(NULL, prefix);
    ASSERT_EQ(LOCK, prefix->value);
    ASSERT_EQ(NULL, prefix->next);
    free_prefixes(prefix);
}

TEST(Prefix, TwoPrefixCheck) {
    uint8_t memory[] = {0xF0, 0xF2, 0, 0};
    PrefixList *prefix = get_prefixes((const void *)memory);
    ASSERT_NE(NULL, prefix);
    ASSERT_EQ(LOCK, prefix->value);
    ASSERT_NE(NULL, prefix->next);
    ASSERT_EQ(REPNE, prefix->next->value);
    ASSERT_EQ(NULL, prefix->next->next);
    free_prefixes(prefix);
}

TEST(Prefix, FourPrefixCheck) {
    uint8_t memory[] = {0xF0, 0xF2, 0xF3, 0x2E};

    PrefixList *prefix = get_prefixes((const void *)memory);
    ASSERT_NE(NULL, prefix);
    ASSERT_EQ(LOCK, prefix->value);
    ASSERT_NE(NULL, prefix->next);
    ASSERT_EQ(REPNE, prefix->next->value);
    ASSERT_NE(NULL, prefix->next->next);
    ASSERT_EQ(REPE, prefix->next->next->value);
    ASSERT_NE(NULL, prefix->next->next->next);
    ASSERT_EQ(SEG_OVERRIDE_CS, prefix->next->next->next->value);
    ASSERT_EQ(NULL, prefix->next->next->next->next);
    free_prefixes(prefix);
}

TEST(Prefix, FivePrefixExpectFourPrefixes) {
    uint8_t memory[] = {0xF0, 0xF2, 0xF3, 0x2E, 0x36};

    PrefixList *prefix = get_prefixes((const void *)memory);
    ASSERT_NE(NULL, prefix);
    ASSERT_EQ(LOCK, prefix->value);
    ASSERT_NE(NULL, prefix->next);
    ASSERT_EQ(REPNE, prefix->next->value);
    ASSERT_NE(NULL, prefix->next->next);
    ASSERT_EQ(REPE, prefix->next->next->value);
    ASSERT_NE(NULL, prefix->next->next->next);
    ASSERT_EQ(SEG_OVERRIDE_CS, prefix->next->next->next->value);
    ASSERT_EQ(NULL, prefix->next->next->next->next);
    free_prefixes(prefix);
}

TEST(Prefix, PrefixAfterNonPrefixExpectNull) {
    uint8_t memory[] = {0, 0xF0};

    PrefixList *prefix = get_prefixes((const void *)memory);
    ASSERT_EQ(NULL, prefix);
}
