#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

simplequeue * new_queue() {
    simplequeue *q = malloc(sizeof(simplequeue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

queuenode * build_queuenode() {
    queuenode *new = malloc(sizeof(queuenode));
    new->next = NULL;
    return new;
}

queuenode * read_queuenode() {
    queuenode *new = build_queuenode();
    printf("Provide a name: ");
    scanf("%[^\n]%*c", new->name);
    return new;
}

void queue_add(simplequeue *queue, queuenode *new_node) {
    if (queue->head == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
        return;
    }
    queuenode *last = queue->tail;
    queue->tail = new_node;
    last->next = new_node;
}

queuenode *queue_peek(simplequeue *queue) {
    if (queue->head == NULL) {
        return NULL;
    }
    queuenode *peek = build_queuenode();
    strcpy(peek->name, queue->head->name);
    return peek;
}

queuenode *queue_poll(simplequeue *queue) {
    if (queue->head == NULL) {
        return NULL;
    }
    queuenode *new_head = queue->head->next;
    queuenode *to_remove = queue->head;
    to_remove->next = NULL;
    queue->head = new_head;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    return to_remove;
}

void print_queuenode(queuenode *n) {
    printf("Name: %s\n", n->name);
}

void print_queue(simplequeue *queue) {
    printf("\nbegin...\n");
    queuenode *actual = queue->head;
    while(actual != NULL) {
        print_queuenode(actual);
        actual = actual->next;
    }
    printf("...end\n");
}

void clear_queue(simplequeue *queue) {
    while(queue_poll(queue) != NULL);
}
