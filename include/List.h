/**
 * List.h
 *
 * Defines a `List` structure and associated set of functions.
 *
 * The standard for all functions will be to return either `EXIT_SUCCESS` on
 * successful execution or `EXIT_FAILURE` if errors occur. Specific error codes
 * may be available as [out] parameters when applicable.
 *
 * Warnings!
 *
 * The `List` struct and API functions DO NOT define a specific type of item
 * the List contains (on purpose) and it is the user's responsibility to keep
 * track of what data type is stored.
 *
 * The `List` API provides constructor and destructor functions so that the
 * user does not need to manage memory manually. It is the  responsibility of
 * the user to utilize these functions to for the library to appropriately
 * initialize and clean up memory.
 */
#ifndef _LIST_H
#define _LIST_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    typedef struct List {
        size_t item_size;
        int count;
        int capacity;
        void *arr;
    } List;

    /* Constructor and destructor */
    List * list_new(List *list, size_t size);
    void list_destroy(List *list);

    /* Utility functions */
    void * list_value_at(const List *list, int index, void *value);

    /* Modifiers */
    void * list_add(List *list, void *item);
    int list_set(List *list, int index, void *item);
    int list_remove_at(List *list, int index);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _LIST_H
