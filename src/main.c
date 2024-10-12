#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "List.h"

int main(int argc, char *argv[])
{
    fprintf(stderr, "testing\n");

    // Create new char List
    List my_list;
    list_new(&my_list, sizeof(int));

    int x = 3;
    void *src = &x;
    void *temp = memcpy(my_list.arr, src, sizeof(int));
    if (NULL == temp) { 
        fprintf(stderr, "error copying data to array.\n");
    }
    void *value = malloc(sizeof(int *));
    temp = memcpy(value, my_list.arr, my_list.item_size);
    int *y = value;
    fprintf(stderr, "added value (%d) to array.\n", *y);


}
