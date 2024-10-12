/**
 * list.c
 *
 * public and private list functions
 */

#include <stdlib.h>
#include <memory.h>

#include "List.h"


/* ------ private function declarations ------ */
int ensure_capacity(List *list);

/* ------ macro definitions ------ */
#define DEFAULT_LIST_INIT 10
#define NORMAL 1
#define ERROR 0

/* ------ public functions ------ */

/* Constructor and destructor */

List * list_new(List *list, size_t size)
{
    if (0 >= size) { return NULL; }

    list->capacity = DEFAULT_LIST_INIT;
    list->count = 0;
    list->item_size = size;
    list->arr = malloc(list->item_size * (list->capacity + 1));

    if (NULL == list->arr) { return NULL; }

    return list;
}

void list_destroy(List *list)
{
    list->item_size = 0;
    list->count = 0;
    list->capacity = 0;
    free(list->arr);
    list->arr = NULL;
}

/* Utility functions */

void list_value_at(const List *list, int index, void *value)
{
    if (list->capacity <= index) { 
        value = NULL;
        return; 
    }

    size_t jump = list->item_size * index;

    void *temp = memcpy(value, list->arr + jump, list->item_size);

    if (NULL == temp) { 
        value = NULL;
        return; 
    }
}

/* Modifiers */
// TODO: Implement this.
void list_add(List *list, void *item) 
{
    // Check that list has space.
    if (NORMAL != ensure_capacity(list)) {
        return;
    }

    // Get last (n) position in list.
    //
    // list->arr is pointer to start of array
    //
    // value at index 0 is = *(list->arr + 0 * item_size)
    // value at index 1 is = *(list->arr + 1 * item_size)
    // ...
    // value of last item, index list->count, is = *(list->arr + list->count * item_size)

    // Copy over value to arr[n + 1].
    // void *temp = memcpy(value, list->arr + jump, list->item_size);
    void *position = (list->arr + (list->count + 1) * list->item_size);
    void *temp = memcpy(position, item, list->item_size);
    
    // Double check that item was copied over correctly.
    if (NULL == temp) { 
        return;
    }

    // Increment count.
    list->count++;
}

// TODO: Implement this.
int list_remove_at(List *list, int index);

/* ------ private function definitions ------ */

int ensure_capacity(List *list)
{
    // If count is less than capacity, there is room for another element.
    if (list->count < (list->capacity)) {
        return NORMAL;
    }
    else {
        // If we are at capacity, double it to avoid excessive memory
        // allocations.
        list->capacity *= 2;
        list->arr = realloc(list->arr, list->item_size * (list->capacity + 1));

        // Check that memory was allocated correctly.
        if (NULL == list->arr) {
            return ERROR;
        }

        return NORMAL;
    }
}
