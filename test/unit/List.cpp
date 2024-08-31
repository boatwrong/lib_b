#include <memory.h>
#include "gtest/gtest.h"

extern "C" {
#include "List.h"
}

TEST(copy, return_dest) {
    char src[] = "hello";
    char dst[sizeof(src)];
    void *rv = memcpy(dst, src, sizeof(src));
    ASSERT_EQ(rv, dst);
}
