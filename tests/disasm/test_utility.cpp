#include <gtest/gtest.h>

#include "disasm/utility.h"

TEST(Utility, MallocAndFreeExpectSuccess) {
    void *mem = local_malloc(1000);
    ASSERT_NE(NULL, mem);
    local_free(mem);
}

TEST(Utility, MallocSizeZeroExpectNull) {
    void *mem = local_malloc(0);
    ASSERT_EQ(NULL, mem);
}

TEST(Utility, MallocCheckZeroed) {
    uint8_t *mem = (uint8_t *)local_malloc(1000 * sizeof(uint8_t));
    for (int i = 0; i < 1000; ++i) {
        ASSERT_EQ(0, mem[i]);
    }
    local_free(mem);
}

TEST(Utility, FreeNullExpectSuccess) { local_free(NULL); }

TEST(Utility, MemzeroNullExpectSuccess) { local_memzero(NULL, 1000); }

TEST(Utility, MemzeroSizeZeroExpectSuccess) {
    void *mem = local_malloc(1000);
    local_memzero(mem, 0);
    local_free(mem);
}
