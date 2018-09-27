#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct q_item {
  double item;
  q_item next;
};
struct queue {
  q_item first;
  q_item last;
  int length;
};

q_item q_item_create(double item) {
  q_item node = malloc(sizeof *node);
  node->item = item;
  node->next = NULL;
  return node;
}

queue queue_new() {
  queue q = malloc(sizeof *q);
  q->first = NULL;
  q->last = NULL;
  q->length = 0;
  return q;
}

void node_free(q_item first) {
  q_item temp;
  if (first->next == NULL) {
    free(first);
  } else {
    temp = first->next;
    free(first);
    node_free(temp);
  }
}
queue queue_free(queue q) {
  if (q->length > 0) {
    node_free(q->first);
    free(q);
  }
  return NULL;
}

void enqueue(queue q, double item) {
  if (q->length < 1) {
    q->first = q_item_create(item);
    q->last = q->first;
    q->length++;
  } else {
    q_item new = q_item_create(item);
    q->last->next = new;
    q->last = new;
    q->length++;
  }
}

double dequeue(queue q) {
  double result;
  q_item temp;
  if (q->length > 0) {
    result = q->first->item;
    temp = q->first;
    q->first = q->first->next;
    temp->next = NULL;
    node_free(temp);
    q->length--;
    return result;
  } else {
    printf("Queue empty!\n");
    exit(1);
  }
}

void node_print(q_item first) {
  if (first->next == NULL) {
    printf("%.2f\n", first->item);
  } else {
    printf("%.2f\t", first->item);
    node_print(first->next);
  }
}

void queue_print(queue q) {
  if (q->length > 0) {
    printf("Printing...\n");
    node_print(q->first);
  }
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
  printf("Remove: %.2f\n", temp);

  temp = dequeue(q);
  printf("Remove: %.2f\n", temp); 

  queue_print(q);

  queue_free(q);
  
  printf("Reached EOF\n");  
  return EXIT_SUCCESS;
}
