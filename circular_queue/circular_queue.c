#include "circular_queue.h"
#include <stdlib.h>

void cq_create(cqueue **q, int capa)
{
  *q              = (cqueue *)malloc(sizeof(cqueue));
  (*q)->container = (node *)malloc(sizeof(node) * (capa + 1));
  (*q)->front     = 0;
  (*q)->rear      = 0;
  (*q)->capacity  = capa;
}

void cq_destroy(cqueue *q)
{
  free(q->container);
  free(q);
}

void cq_enqueue(cqueue *q, value_type v)
{
  int pos = q->rear;
  if (pos == q->capacity) {
    q->rear = 0;
  } else {
    q->rear++;
  }
  q->container[pos].value = v;
}

value_type cq_dequeue(cqueue *q)
{
  int pos = q->front;
  if (pos == q->capacity) {
    q->front = 0;
  } else {
    q->front++;
  }
  return q->container[pos].value;
}

int cq_size(cqueue *q)
{
  if (q->front <= q->rear) {
    return q->rear - q->front;
  } else {
    return q->capacity - q->front + 1 + q->rear;
  }
}

bool cq_empty(cqueue *q) {
	return cq_size(q) == 0;
}

bool cq_full(cqueue *q) {
	if (q->front < q->rear) {
		return (q->rear - q->front) == q->capacity;
	} else {
		return q->rear + 1 == q->front;
	}
}