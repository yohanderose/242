#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "queue.h"

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
    g->links[neighbour][node] = 1;
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

void graph_bfs(graph g, int source) {
  int i, node;
  queue q;

  /* Set each node to unvisited settings.  */
  for (i = 0; i < g->size; i++) {
    g->nodes[i].parent = -1;
    g->nodes[i].dist = -1;
    g->nodes[i].state = UNVISITED;
  }

  /* Then grab the source node and update its settings. */
  q = queue_new();
  enqueue(q, source);
  g->nodes[source].state = VISITED_SELF;
  g->nodes[source].dist = 0;

  /* While q is not empty, visit nodes in queue and update them. */
  while (0 != queue_size(q)) {
    node = dequeue(q);
    for (i=0; i<g->size; i++) {
      if (g->links[node][i] == 1 && g->nodes[i].state == UNVISITED){
	g->nodes[i].parent = node;
	g->nodes[i].dist = g->nodes[node].dist + 1;
	g->nodes[i].state = VISITED_SELF;
	enqueue(q, i);
      }
    }
    g->nodes[node].state = VISITED_DESCENDANTS;
  }
  queue_free(q);
}

/* Display information on each node after bfs. */
void graph_print_dist_pred(graph g) {
  int i;
  printf("vertex distance pred\n");
  for (i=0; i<g->size; i++) {
    printf("%5d %5d %5d\n", i, g->nodes[i].dist, g->nodes[i].parent);
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
  graph_bfs(g, 1);
  graph_print_dist_pred(g);
  graph_free(g);
  
  return EXIT_SUCCESS;
}
