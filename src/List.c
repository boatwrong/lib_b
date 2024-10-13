/**
 * list.c
 *
 * public and private list functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "List.h"

#define NORMAL 1
#define ERROR 0


/* ------ private function declarations ------ */
int ensure_capacity(List *list);

/* ------ macro definitions ------ */
#define DEFAULT_LIST_INIT 10

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

void * list_value_at(const List *list, int index, void *value)
{
    // Check for valid index.
    if ((list->count <= index) || (list->capacity <= index)) { 
        return NULL; 
    }


    // Calculate position of value to retrieve based on List's defined number
    // of bytes per item.
    size_t position = list->item_size * index;

    // Retrieve item from list.
    void *temp = memcpy(value, list->arr + position, list->item_size);

    return temp;

    // // Check that item was retrieved successfully.
    // if (NULL == temp) { 
    //     value = NULL;
    //     return; 
    // }
}

/* Modifiers */
void * list_add(List *list, void *item) 
{
    // Check that list has space.
    if (NORMAL != ensure_capacity(list)) {
        // This means that the memory check and subsequent attempt to increase
        // the capacity of the List failed. Return early.
        return NULL;
    }

    // Get last (n) position in list.
    //
    // list->arr is pointer to start of array
    //
    // value at index 0 is = *(list->arr + 0 * item_size)
    // value at index 1 is = *(list->arr + 1 * item_size)
    // ...
    // // Because list is 0-indexed, the value of last item, relative to the
    // // count is:
    // *(list->arr + (list->count - 1) * item_size)
    // ...
    // // And appending an item would be done at:
    // *(list->arr + list->count * item_size)

    // Copy over value to arr[n + 1].
    // void *temp = memcpy(value, list->arr + position, list->item_size);
    void *position = (list->arr + list->count * list->item_size);
    void *temp = memcpy(position, item, list->item_size);
    
    // Double check that item was copied over correctly.
    if (NULL != temp) { 
        // Increment count.
        list->count++;
    }

    return temp;
}

int list_set(List *list, int index, void *item) 
{
    // Check for valid index.
    if ((list->count <= index) || (list->capacity <= index)) { 
        fprintf(stderr, "%s\n","Index out of bounds.");
        return ERROR; 
    }

    // Calculate position within list to modify.
    void *position = (list->arr + (index) * list->item_size);

    // Modify the item in the List.
    void *temp = memcpy(position, item, list->item_size);
    
    // Double check that item was copied over correctly.
    if (NULL == temp) { 
        fprintf(stderr, "%s\n","Value not copied correctly.");
        return ERROR;
    }

    return NORMAL;
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
            fprintf(stderr, "Unable to allocate memory\n");
            return ERROR;
        }

        return NORMAL;
    }
}
