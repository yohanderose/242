#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

int step;

/* Allocates an empty graph with nodeCount 'floating' nodes*/
graph graph_new(int nodeCount) {
  int i, j;
  graph result = malloc(sizeof *result);
  result->size = nodeCount;
  result->nodes = malloc(nodeCount*sizeof(struct node));
  result->links = malloc(sizeof(result[0])*nodeCount);
  for (i=0; i<nodeCount; i++) {
    result->links[i] = malloc(sizeof(result[0])*nodeCount);
    for (j=0; j<nodeCount; j++) {
      result->links[i][j] = 0;
    }
  }
  return result;
}

/* Frees the links and the nodes and finally the graph itself. */
void graph_free(graph g) {
  int i;
  free(g->nodes);
  for(i=0; i<g->size; i++) {
    free(g->links[i]);
  }
  free(g->links);
  free(g);
}

/* Establish 2-way link between two nodes. */
void graph_add_link(graph g, int node, int neighbour) {
  if (node<g->size && neighbour<g->size) {
    g->links[node][neighbour] = 1;
  }
}

/* Cycle through each node and print its neighbours. */
void graph_print_adjacent(graph g) {
  int i, j, first;
  printf("adjacency list:\n");
  for (i = 0; i < g->size; i++) {
    printf("%d |", i);
    first = 1;
    for (j = 0; j < g->size; j++) {
      if (g->links[i][j] == 1 && first == 1) {
	printf(" %d", j);
	first--;
      } else if (g->links[i][j] == 1) {
	printf(", %d", j);
      }
    }
    printf("\n");
  }
  printf("\n");
}

/*Recursive function that adjusts the settings of a node during a dfs. */
void visit(int n, graph g) {
  int i;
  g->nodes[n].state = VISITED_SELF;
  step++;
  g->nodes[n].dist = step;
  for (i=0; i<g->size; i++) {
    if (1 == g->links[n][i] && g->nodes[i].state == UNVISITED) {
      g->nodes[i].parent = n;
      visit(i,  g);
    }
  }
  step++;
  g->nodes[n].state = VISITED_DESCENDANTS;
  g->nodes[n].finish = step;
}

/*Examine each node in the graph independently. */
void graph_dfs(graph g) {
  int i;
  for (i=0; i<g->size; i++) {
    g->nodes[i].state = UNVISITED;
    g->nodes[i].parent = -1;
  }
  step = 0;
  for (i=0; i<g->size; i++) {
    if (g->nodes[i].state == UNVISITED) {
      visit(i, g);
    }
  }
}

/* Display information on each node after dfs. */
void graph_print_dist_pred(graph g) {
  int i;
  printf("vertex distance pred finish\n");
  for (i=0; i<g->size; i++) {
    printf("%5d %5d %5d %5d\n", i, g->nodes[i].dist, g->nodes[i].parent, g->nodes[i].finish);
  }
}

int main(void) {
  graph g;
  int nodeCount, node, neighbour;
  
  /*Read in desired number of nodes and create graph.*/
  printf("Size of graph: ");
  scanf("%d", &nodeCount);
  g = graph_new(nodeCount);

  /*Define relationships between nodes. */
  while (2 == scanf("%d %d", &node, &neighbour)) {
    graph_add_link(g, node, neighbour);
  }
  graph_print_adjacent(g);

  /*Perform a bfs, output results and deallocate memory. */
  graph_dfs(g);
  graph_print_dist_pred(g);
  graph_free(g);
  
  return EXIT_SUCCESS;
}
