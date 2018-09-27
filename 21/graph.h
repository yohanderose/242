#ifndef GRAPH_H__
#define GRAPH_H_
#include <stdio.h>

/* Possible states of a node during a search. */
enum state_e {
    UNVISITED,
    VISITED_SELF,
    VISITED_DESCENDANTS
};

/* Vertex in the graph with attributes. */
struct node {
    int parent; 
    int dist;
    enum state_e state;
    int finish;
};

/* Main object comprised of nodes and links between them. */
struct graph {
    int size;
    struct node *nodes;
    int **links;
};

typedef struct graph *graph;
extern graph graph_new(int nodeCount);
extern void graph_free(graph g);
extern void graph_add_link(graph g, int node, int neighbour);
extern void graph_print_adjacent(graph g);
extern void graph_print_dist_pred(graph g);
extern void graph_dfs(graph g);
extern void visit(int n, graph g);

#endif
