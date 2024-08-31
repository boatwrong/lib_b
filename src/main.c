#include <stdio.h>

#include "List.h"

int main(int argc, char *argv[])
{
    fprintf(stderr, "testing\n");

    // Create new char List
    List arr;
    list_new(&arr, sizeof(char));
}
