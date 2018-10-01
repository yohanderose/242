#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"
struct queue {
  int num_items;
  int head;
  int capacity;
  double *items;
};
queue queue_new() {
  int default_size = 7;
  queue q = emalloc(sizeof *q);
  q->num_items = 0;
  q->head = 0;
  q->capacity = default_size;
  q->items = emalloc(sizeof(q->items[0]) * default_size);
  return q;
}
queue queue_free(queue q) {
  free(q->items);
  free(q);
  return NULL;
}
void enqueue(queue q, double item) {
  if (q->num_items < q->capacity) {
    q->items[(q->head + q->num_items++) % q->capacity] = item;
  }
}
double dequeue(queue q) {
  double result = -1;
  if (q->num_items > 0) {
    result = q->items[q->head];
    q->items[q->head++] = 0;
    q->num_items--;
  }
  return result;
}
void queue_print(queue q) {
  /* print queue contents one per line to 2 decimal places */
  int i = 0, head = q->head;
  while (i<q->num_items) {
    printf("%.2f\n", q->items[q->head++%q->capacity]);
    i++;
  }
  q->head = head;
}
void queue_print_info(queue q) {
  int i;
  printf("capacity %d, num_items %d, head %d\n[", q->capacity,
	 q->num_items, q->head);
  for (i = 0; i < q->capacity; i++) {
    printf("%s%.2f", i == 0 ? "" : ", ", q->items[i]);
  }
  printf("]\n");
}
int queue_size(queue q) {
  return q->num_items;
}


