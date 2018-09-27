#ifndef QUEUE_H_
#define QUEUE_H_

#include "graph.h"

typedef struct queue *queue;

extern queue queue_new();
extern void enqueue(queue q, int item);
extern int dequeue(queue q);
extern void queue_print(queue q);
extern int queue_size(queue q);
extern queue queue_free(queue q);

#endif
