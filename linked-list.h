
typedef struct linked_list {
    struct list_node *first;
    struct list_node *last;
} linkedlist;

typedef struct list_node {
    char name[256];
    struct list_node *next;
} listnode;

linkedlist * new_linkedlist();
listnode *build_listnode();
listnode *read_listnode();
void print_listnode(listnode *n);
void insertion(linkedlist *list, listnode *new);
void delete_last(linkedlist *list);
listnode *search(linkedlist *list, char *name);
void delete_with_name(linkedlist *list, char *name);
void reverse(linkedlist *list);
void traverse(linkedlist *list);
void update(linkedlist *list, char *old_name, char *new_name);
void insertion_sort(linkedlist *list, listnode *new);
int is_lower_than_first(linkedlist *list, listnode *new);
int is_bigger_than_last(linkedlist *list, listnode *new);
int is_lower_than(listnode *ln1, listnode *ln2);
int is_bigger_than(listnode *ln1, listnode *ln2);
int sort_strings_asc(const void *str1, const void *str2);
int sort_strings_desc(const void *str1, const void *str2);
char ** sort(linkedlist *list, int order);
void sort_asc(linkedlist *list);
void sort_desc(linkedlist *list);
linkedlist * merge(linkedlist *a, linkedlist *b);
