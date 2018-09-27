#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

#include "memlib.h"

typedef struct q_item *q_item;

struct q_item
{
    int item;
    q_item next;
};

struct queue
{
    q_item first;
    q_item last;
    int length;
};

queue queue_new()
{
    queue q = emalloc(sizeof *q);
    q->first = NULL;
    q->last = NULL;
    q->length = 0;

    return q;
}

void enqueue(queue q, int item)
{
    q_item node = emalloc(sizeof *node);
    node->item = item;
    node->next = NULL;

    if (q->first == NULL)
    {
        q->first = node;
        q->last = node;
    }
    else
    {
        q->last->next = node;
        q->last = node;
    }

    q->length++;
}

int dequeue(queue q)
{
    int result;
    q_item item;

    if (q->length == 0)
    {
        fprintf(stderr, "Tried to dequeue on an empty queue.\n");
        exit(EXIT_FAILURE);
    }

    item = q->first;
    q->first = q->first->next;
    q->length--;

    result = item->item;
    free(item);

    return result;
}

void queue_print(queue q)
{
    int i;

    q_item node = q->first;
    for (i = 0; i < q->length; i++)
    {
        printf("%x\n", node->item);
        node = node->next;
    }
}

int queue_size(queue q)
{
    return q->length;
}

queue queue_free(queue q)
{
    int i;

    q_item node = q->first;
    for (i = 0; i < q->length; i++)
    {
        free(node);
        node = node->next;
    }

    free(q);

    return NULL;
}

