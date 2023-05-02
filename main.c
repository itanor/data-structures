#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "linked-list.h"

int main(int argc, char *argv[]) {
    linkedlist *a = new_linkedlist();

    insertion_sort(a, read_listnode());
    insertion_sort(a, read_listnode());
    insertion_sort(a, read_listnode());
    insertion_sort(a, read_listnode());
    insertion_sort(a, read_listnode());

    traverse(a);

    linkedlist *b = new_linkedlist();

    insertion_sort(b, read_listnode());
    insertion_sort(b, read_listnode());
    insertion_sort(b, read_listnode());
    insertion_sort(b, read_listnode());

    traverse(b);

    linkedlist *merged = merge(a, b);

    traverse(merged);

    return 0;
}
