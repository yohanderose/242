#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdio.h>

enum state_e
{
    UNVISITED,
    VISITED_SELF,
    VISITED_DESCENDANTS
};

struct vertex
{
    int predecessor; 
    int distance;
    enum state_e state;
    int finish;
};

struct graphrec
{
    int size;
    struct vertex *vertices;
    int **edges;
};

typedef struct graphrec *graph;

extern graph    graph_new(int vertices);
extern void     graph_free(graph g);
extern void     graph_add_edge_uni(graph g, int u, int v);
extern void     graph_add_edge_bi(graph g, int u, int v);
extern void     graph_print_adjacent(graph g);
extern void     graph_print_dist_pred(graph g);
extern void     graph_bfs(graph g, int source);

#endif
