#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "linked-list.h"

linkedlist * new_linkedlist() {
    linkedlist *new = malloc(sizeof(linkedlist));
    new->first = NULL;
    new->last = NULL;
    return new;
}

listnode *build_listnode() {
    listnode *new = malloc(sizeof(listnode));
    new->next = NULL;
    return new;
}

listnode *read_listnode() {
    listnode *new = build_listnode();
    printf("Provide a name: ");
    scanf("%[^\n]%*c", new->name);
    return new;
}

void print_listnode(listnode *n) {
    printf("name: %s\n", n->name);
}

void insertion(linkedlist *list, listnode *new) {
    if (list->first == NULL) {
        list->first = list->last = new;
        return;
    }
    list->last->next = new;
    list->last = new;
}

int is_lower_than_first(linkedlist *list, listnode *new) {
    return is_lower_than(new, list->first);
}

int is_lower_than(listnode *ln1, listnode *ln2) {
    return strcmp(ln1->name, ln2->name) < 0;
}

int is_bigger_than_last(linkedlist *list, listnode *new) {
    return is_bigger_than(list->last, new);
}

int is_bigger_than(listnode *ln1, listnode *ln2) {
    return strcmp(ln1->name, ln2->name) < 0;
}

void insertion_sort(linkedlist *list, listnode *new) {
    listnode * n = build_listnode();
    strcpy(n->name, new->name);

    if (list->first == NULL) {
        insertion(list, n);
        return;
    }
    if (is_lower_than_first(list, n)) {
        n->next = list->first;
        list->first = n;
        return;
    }
    if (is_bigger_than_last(list, n)) {
        list->last->next = n;
        list->last = n;
        return;
    }
    listnode *actual = list->first;
    listnode *before = list->first;
    while (is_bigger_than(actual, n)) {
        before = actual;
        actual = actual->next;
    }
    before->next = n;
    n->next = actual;
}

void delete_last(linkedlist *list) {
    if (list->last == NULL) {
        return;
    }
    if (list->first == list->last) {
        listnode *to_free = list->last;
        list->first = list->last = NULL;
        free(to_free);
        return;
    }
    listnode *actual = list->first;
    while (actual->next != list->last) {
        actual = actual->next;
    }
    listnode *to_free = list->last;
    actual->next = NULL;
    list->last = actual;
    free(to_free);
}

listnode *search(linkedlist *list, char *name) {
    listnode *actual = list->first;
    while (actual != NULL) {
        if (strcmp(name, actual->name) == 0) {
            return actual;
        }
        actual = actual->next;
    }
    return NULL;
}

void delete_with_name(linkedlist *list, char *name) {
    listnode *found = search(list, name);
    if (found == NULL) {
        return;
    }
    if (list->first == list->last) {
        free(found);
        list->first = list->last = NULL;
        return;
    }
    listnode *actual = list->first;
    listnode *after  = list->last;
    if (found->next != NULL) {
        after = found->next;
    }
    if (found == list->first) {
        list->first = list->first->next;
        free(found);
        return;
    }
    while (actual->next != found) {
        actual = actual->next;
    }
    actual->next = after;
    if (found == list->last) {
        actual->next = NULL;
        list->last = actual;
    }
    free(found);
}

linkedlist * merge(linkedlist *a, linkedlist *b) {
    linkedlist *merged = new_linkedlist();

    void insert_all_in(linkedlist *l, listnode *n) {
        while (n != NULL) {
            insertion_sort(l, n);
            n = n->next;
        }
    }
    listnode *actual = a->first;
    insert_all_in(merged, actual);
    actual = b->first;
    insert_all_in(merged, actual);
    return merged;
}

void sort_asc(linkedlist *list) {
    sort(list, 1);
}

void sort_desc(linkedlist *list) {
    sort(list, 0);
}

char ** sort(linkedlist *list, int order) {
    if (list->first == NULL) {
        return NULL;
    }
    listnode *actual = list->first;
    int elements = 0;
    while (actual != NULL) {
        elements++;
        actual = actual->next;
    }
    char **names = malloc(elements * sizeof(char*));
    for (int i = 0; i < elements; i++) {
        names[i] = malloc((255+1) * sizeof(char));
    }
    int i = 0;
    actual = list->first;
    while(actual != NULL) {
        names[i++] = actual->name;
        actual = actual->next;
    }

    int (*sort_strings)(const void *str1, const void *str2);
    if (order) sort_strings = sort_strings_asc;
    else sort_strings = sort_strings_desc;
    qsort(names, elements, sizeof(char *), sort_strings);
    for (int i = 0; i < elements; i++) {
        printf("%s\n", names[i]);
    }
    return names;
}

int sort_strings_asc(const void *str1, const void *str2) {
    const char* aa = *(const char**)str1;
    const char* bb = *(const char**)str2;
    return strcmp(aa, bb);
}

int sort_strings_desc(const void *str1, const void *str2) {
    const char* aa = *(const char**)str1;
    const char* bb = *(const char**)str2;
    return strcmp(bb, aa);
}

void update(linkedlist *list, char *old_name, char *new_name) {
    listnode *found = search(list, old_name);
    if (found == NULL) {
        return;
    }
    strcpy(found->name, new_name);
}

void reverse(linkedlist *list) {
    stack * stack = new_stack();
    listnode *actual = list->first;
    while (actual != NULL) {
        stacknode *node = build_stacknode();
        strcpy(node->name, actual->name);
        push(stack, node);
        actual = actual->next;
    }
    print_stack(stack);
    clear_stack(stack);
}

void traverse(linkedlist *list) {
    printf("begin...\n");
    listnode *actual = list->first;
    while (actual != NULL) {
        print_listnode(actual);
        actual = actual->next;
    }
    printf("..end\n");
}
