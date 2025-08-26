#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "linked-list.h"
#include "queue.h"

void do_with_linked_list() {
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
}

void do_with_queue() {
    simplequeue *q = new_queue();
    queue_add(q, read_queuenode());
    print_queue(q);
    queue_add(q, read_queuenode());
    print_queue(q);
    queue_add(q, read_queuenode());
    print_queue(q);
    queue_poll(q);
    print_queue(q);
    queue_add(q, read_queuenode());
    queue_add(q, read_queuenode());
    print_queue(q);
    clear_queue(q);
}

int main(int argc, char *argv[]) {
    // do_with_linked_list();
    do_with_queue();
    return 0;
}
