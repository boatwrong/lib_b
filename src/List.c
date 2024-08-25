/**
 * list.c
 *
 * public and private list functions
 */

#include <stdlib.h>
#include <memory.h>

#include "List.h"


/* ------ macro definitions ------ */
#define DEFAULT_LIST_INIT 10

/* ------ public functions ------ */

/* Constructor and destructor */

int list_new(List *list, size_t size)
{
    if (0 >= size) {
        return EXIT_FAILURE;
    }

    list->capacity = DEFAULT_LIST_INIT;
    list->count = 0;
    list->arr = malloc(size * list->capacity);

    if (NULL == list->arr) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int list_destroy(List *list)
{
    list->item_size = 0;
    list->count = 0;
    list->capacity = 0;
    free(list->arr);
    return EXIT_SUCCESS;
}

/* Utility functions */

int list_value_at(const List *list, int index, void *value)
{
    if (list->capacity <= index) {
        return EXIT_FAILURE;
    }

    size_t jump = list->item_size * index;

    void *temp = memcpy(value, list->arr + jump, list->item_size);
    if (NULL == temp) { 
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

/* Modifiers */
// TODO: Implement this.
int list_add(List *list, void *item);

// TODO: Implement this.
int list_remove_at( List *list, int index);
