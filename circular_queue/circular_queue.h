#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>

typedef int value_type;

typedef struct node {
	value_type value;
} node;

typedef struct cqueue {
	int capacity;
	int front;
	int rear;
	node *container;
} cqueue;

void cq_create(cqueue **q, int capa);
void cq_destroy(cqueue *q);
void cq_enqueue(cqueue *q, value_type v);
value_type cq_dequeue(cqueue *q);
int cq_size(cqueue *q);
bool cq_empty(cqueue *q);
bool cq_full(cqueue *q);

#endif