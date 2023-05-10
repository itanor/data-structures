
typedef struct double_linked_list {
    struct double_list_node *first;
    struct double_list_node *last;
} doublelinkedlist;

typedef struct double_list_node {
    char name[256];
    struct double_list_node *prev;
    struct double_list_node *next;
} doublelistnode;

doublelinkedlist * new_doublelinkedlist();
doublelistnode *build_doublelistnode();
doublelistnode *read_doublelistnode();
void print_doublelistnode(doublelistnode *n);
void insertion_dll(doublelinkedlist *list, doublelistnode *new);
void delete_last_dll(doublelinkedlist *list);
doublelistnode *search_dll(doublelinkedlist *list, char *name);
void delete_with_name_dll(doublelinkedlist *list, char *name);
void reverse_dll(doublelinkedlist *list);
void traverse_dll(doublelinkedlist *list);
void update_dll(doublelinkedlist *list, char *old_name, char *new_name);
void insertion_sort_dll(doublelinkedlist *list, doublelistnode *new);
int is_lower_than_first_dll(doublelinkedlist *list, doublelistnode *new);
int is_bigger_than_last_dll(doublelinkedlist *list, doublelistnode *new);
int is_lower_than_dll(doublelistnode *ln1, doublelistnode *ln2);
int is_bigger_than_dll(doublelistnode *ln1, doublelistnode *ln2);
/*int sort_strings_asc_dll(const void *str1, const void *str2);
int sort_strings_desc_dll(const void *str1, const void *str2);*/
char ** sort_dll(doublelinkedlist *list, int order);
void sort_asc_dll(doublelinkedlist *list);
void sort_desc_dll(doublelinkedlist *list);
doublelinkedlist * merge_dll(doublelinkedlist *a, doublelinkedlist *b);
