#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"

typedef struct q_item *q_item;
q_item temp;

struct q_item {
  double item;
  q_item next;
};
struct queue {
  int length;
  q_item first;
  q_item last;
};

queue queue_new() {
  queue q = emalloc(sizeof *q);
  q->length = 0;
  q->first = NULL;
  q->last = NULL;
  return q;
}

void queue_free_aux(q_item i) {
  free(i);
}
queue queue_free(queue q) {
  while (q->first != NULL) {
    temp = q->first;
    q->first = q->first->next;
    free(temp);
  }
  free(q);
  return NULL;
}

void enqueue(queue q, double item) {
  q_item i = emalloc(sizeof *i);
  i->item = item;
  i->next = NULL;
  if (q->length == 0) {
    q->first = i;
  } else {
    q->last->next = i;
  }
  q->last = i;
  q->length++;
}
double dequeue(queue q) {
  double result;
  result = q->first->item;
  temp = q->first;
  q->first = q->first->next;
  free(temp);
  q->length--;
  return result;
}
void queue_print(queue q) {
  /* print queue contents one per line to 2 decimal places */
  temp = q->first;
  while (temp != NULL) {
    printf("%.2f\n", temp->item);
    temp = temp->next;
  }
}
void queue_print_info(queue q) {
  if (q->length == 0) {
    printf("The queue is empty\n");
  } else {
    printf("first %.2f, last %.2f, length %d\n", q->first->item,
	   q->last->item, q->length);
  }
}
int queue_size(queue q) {
  return q->length;
}

