#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queue {
  double *items;
  int head;
  int capacity;
  int num_items;
};

queue queue_new() {
  queue q = malloc(sizeof (*q));
  q->items = malloc(sizeof(double) * (5));
  q->head = 0;
  q->capacity = 5;
  q->num_items = 0;
  if (q == NULL) {
    exit(1);
  }
  return q;
}

void enqueue(queue q, double item) {
  if (q->capacity > q->num_items) {
    q->items[(q->head+q->num_items)%q->capacity] = item;
    q->num_items++;
  } else {
    printf("Queue full!\n");
    exit(1);
  }
}

double dequeue(queue q) {
  double result;
  if (q->num_items > 0) {
    q->num_items--;
    result = q->items[q->head];
    q->head++;
    return result;
  } else {
    printf("Queue empty!");
    exit(1);
  }
}

void queue_print(queue q) {
  int i;
  if (q->num_items < 1) {
    printf("Empty queue!\n");
  } else {
    for (i=q->head; i<(q->head+q->num_items); i++) {
      printf("%.2f\n", q->items[i%q->capacity]);
    }
    printf("\n");
  }
}

queue queue_free(queue q) {
  free(q->items);
  free(q);
  return NULL;
}

int main(void) {
  double temp;
  
  queue q = queue_new();
  enqueue(q, 21);
  enqueue(q, 22);
  enqueue(q, 23);
  enqueue(q, 24);
  enqueue(q, 25);  
  queue_print(q);
  
  temp = dequeue(q);
  printf("Dequeue: %f\n", temp);
  queue_print(q);

  printf("Enqueue: 17\n");
  enqueue(q, 17);
  queue_print(q);

  temp = dequeue(q);
  printf("Dequeue: %f\n", temp);
  queue_print(q);

  queue_free(q);

  printf("End of program!\n");
  return EXIT_SUCCESS;
}
