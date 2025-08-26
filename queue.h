
typedef struct simple_queue {
    struct queue_node *head;
    struct queue_node *tail;
} simplequeue;

typedef struct queue_node {
    char name[256];
    struct queue_node *next;
} queuenode;

simplequeue *new_queue();
queuenode   *build_queuenode();
queuenode   *read_queuenode();

void       queue_add(simplequeue *q, queuenode *new_node);
queuenode *queue_peek(simplequeue *q);
queuenode *queue_poll(simplequeue *q);

void print_queuenode(queuenode *n);
void print_queue(simplequeue *q);

void clear_queue(simplequeue *q);