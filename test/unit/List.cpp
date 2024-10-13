#include <memory.h>
#include "gtest/gtest.h"

#include "List.h"

static size_t test_item_size = sizeof(int);

TEST(copy, new_list_item_size) {
    // Create list.
    List my_list;
    list_new(&my_list, test_item_size);

    // Check list content size is correct.
    size_t item_size = my_list.item_size;
    ASSERT_EQ(item_size, test_item_size);

    // Cleanup
    list_destroy(&my_list);
}

TEST(copy, new_list_item_count) {
    // Create list.
    List my_list;
    list_new(&my_list, test_item_size);

    // Check list initial count is correct.
    int item_count = my_list.count;
    ASSERT_EQ(0, item_count);

    // Cleanup
    list_destroy(&my_list);
}

TEST(copy, new_list_capacity) {
    // Create list.
    List my_list;
    list_new(&my_list, test_item_size);

    // Cheating here - I know the initial list should have a capacity of ten
    // so am double checking that.
    ASSERT_EQ(10, my_list.capacity);

    // Cleanup
    list_destroy(&my_list);
}

TEST(copy, new_list_array) {
    // Create list.
    List my_list;
    list_new(&my_list, test_item_size);

    // Check that array was allocated.
    ASSERT_NE(nullptr, my_list.arr);

    // Cleanup
    list_destroy(&my_list);
}

TEST(copy, new_list_destroy) {
    // Create list.
    List my_list;
    list_new(&my_list, test_item_size);
    list_destroy(&my_list);

    // Check that array was allocated.
    ASSERT_EQ(0, my_list.item_size);
    ASSERT_EQ(0, my_list.count);
    ASSERT_EQ(0, my_list.capacity);
    ASSERT_EQ(nullptr, my_list.arr);
}

TEST(copy, value_at) {
    // Create list.
    List my_list;
    list_new(&my_list, test_item_size);

    // Cheat and put a value in the array, increment the count and whatnot.
    int x = 3;
    void *src = &x;
    void *temp = memcpy(my_list.arr, src, sizeof(int));

    // Increment our item count to not fail.
    my_list.count++;

    // Check that value was added correctly.
    ASSERT_NE(nullptr, temp);

    // Retrieve value with accessor function to check equivalence.
    void *res = malloc(sizeof(int *));
    list_value_at(&my_list, 0, res);
    int *y = (int *)res;
    ASSERT_EQ(x, *y);

    // Cleanup
    list_destroy(&my_list);
}


TEST(copy, list_add) {
    // Create list.
    List my_list;
    list_new(&my_list, test_item_size);

    // Cheat and put a value in the array, increment the count and whatnot.
    int x = 3;
    void *src = &x;
    void *temp = list_add(&my_list, src);
    ASSERT_NE(nullptr, temp);

    // Retrieve value with accessor function to check equivalence.
    void *res = malloc(sizeof(int *));
    void *value = list_value_at(&my_list, 0, res);
    ASSERT_NE(nullptr, value);
    int *y = (int *)value;
    ASSERT_EQ(x, *y);

    // Cleanup
    list_destroy(&my_list);
}
