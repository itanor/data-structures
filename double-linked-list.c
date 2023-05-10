#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "linked-list.h"
#include "double-linked-list.h"

doublelinkedlist * new_doublelinkedlist() {
  doublelinkedlist *new = malloc(sizeof(doublelinkedlist));
  new->first = NULL;
  new->last = NULL;
  return new;
}

doublelistnode * build_doublelistnode() {
  doublelistnode *new = malloc(sizeof(doublelistnode));
  new->prev = NULL;
  new->next = NULL;
  return new;
}

doublelistnode * read_doublelistnode() {
  doublelistnode *new = build_doublelistnode();
  printf("Provide a name: ");
  scanf("%[^\n]%*c", new->name);
  return new;
}

void print_doublelistnode(doublelistnode *n) {
  printf("name: %s\n", n->name);
}

void insertion_dll(doublelinkedlist *list, doublelistnode *new) {
  if (list->first == NULL) {
    list->first = list->last = new;
    return;
  }
  list->last->next = new;
  new->prev = list->last;
  list->last = new;
}

void delete_last_dll(doublelinkedlist *list) {
  if (list->last == NULL) {
    return;
  }
  if (list->first == list->last) {
    doublelistnode *to_free = list->last;
    list->first = list->last = NULL;
    free(to_free);
    return;
  }
  doublelistnode *to_free = list->last;
  list->last = list->last->prev;
  list->last->next = NULL;
  free(to_free);
}

doublelistnode *search_dll(doublelinkedlist *list, char *name) {
  doublelistnode *actual = list->first;
  while (actual != NULL) {
    if (strcmp(name, actual->name) == 0) {
      return actual;
    }
    actual = actual->next;
  }
  return NULL;
}

void delete_with_name_dll(doublelinkedlist *list, char *name) {
  doublelistnode *found = search_dll(list, name);
  if (found == NULL) {
    return;
  }
  if (list->first == list->last) {
    free(found);
    list->first = list->last = NULL;
    return;
  }
  if (found == list->last) {
    list->last = list->last->prev;
    list->last->next = NULL;
    free(found);
    return;
  }
  if (found == list->first) {
    list->first = list->first->next;
    list->first->prev = NULL;
    free(found);
  }
  doublelistnode *before = found->prev;
  doublelistnode *after  = found->next;
  before->next = after;
  after->prev = before;
  free(found);
}

void reverse_dll(doublelinkedlist *list) {
  doublelistnode *actual = list->last;
  while (actual != NULL) {
    print_doublelistnode(actual);
    actual = actual->prev;
  }
}

void traverse_dll(doublelinkedlist *list) {
  doublelistnode *actual = list->first;
  while (actual != NULL) {
    print_doublelistnode(actual);
    actual = actual->next;
  }
}

void update_dll(doublelinkedlist *list, char *old_name, char *new_name) {
  doublelistnode *found = search_dll(list, old_name);
  if (found == NULL) {
    return;
  }
  strcpy(found->name, new_name);
}

void insertion_sort_dll(doublelinkedlist *list, doublelistnode *new) {
  doublelistnode * n = build_doublelistnode();
  strcpy(n->name, new->name);

  if (list->first == NULL) {
      insertion_dll(list, n);
      return;
  }
  if (is_lower_than_first_dll(list, n)) {
      n->next = list->first;
      list->first->prev = n;
      list->first = n;
      return;
  }
  if (is_bigger_than_last_dll(list, n)) {
      list->last->next = n;
      n->prev = list->last;
      list->last = n;
      return;
  }
  doublelistnode *actual = list->first;
  doublelistnode *before = list->first;
  while (is_bigger_than_dll(actual, n)) {
      before = actual;
      actual = actual->next;
  }
  before->next = n;
  n->next = actual;
  actual->prev = n;
  n->prev = before;
}

int is_lower_than_first_dll(doublelinkedlist *list, doublelistnode *new) {
  return is_lower_than_dll(new, list->first);
}

int is_bigger_than_last_dll(doublelinkedlist *list, doublelistnode *new) {
  return is_bigger_than_dll(list->last, new);
}

int is_lower_than_dll(doublelistnode *ln1, doublelistnode *ln2) {
  return strcmp(ln1->name, ln2->name) < 0;
}

int is_bigger_than_dll(doublelistnode *ln1, doublelistnode *ln2) {
  return strcmp(ln1->name, ln2->name) < 0;
}

char ** sort_dll(doublelinkedlist *list, int order) {
  if (list->first == NULL) {
    return NULL;
  }
  doublelistnode *actual = list->first;
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

void sort_asc_dll(doublelinkedlist *list) {
  sort_dll(list, 1);
}

void sort_desc_dll(doublelinkedlist *list) {
  sort_dll(list, 0);
}

doublelinkedlist * merge_dll(doublelinkedlist *a, doublelinkedlist *b) {
  doublelinkedlist *merged = new_doublelinkedlist();

  void insert_all_in(doublelinkedlist *l, doublelistnode *n) {
    while (n != NULL) {
      insertion_sort_dll(l, n);
      n = n->next;
    }
  }
  doublelistnode *actual = a->first;
  insert_all_in(merged, actual);
  actual = b->first;
  insert_all_in(merged, actual);
  return merged;  
}
