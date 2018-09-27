#include "graph.h"

#include <stdio.h>
#include <stdlib.h>

#include "memlib.h"
#include "queue.h"

graph graph_new(int vertices)
{
  int i;
  graph g = emalloc(sizeof *g);

  g->size = vertices;
  g->vertices = emalloc(vertices * sizeof (struct vertex));
  g->edges = emalloc(vertices * sizeof g->edges[0]);

  for (i = 0; i < vertices; i++)
    {
      g->edges[i] = ecalloc(vertices, sizeof g->edges[0][0]);
    }

  return g;
}

void graph_free(graph g)
{
  int i;
  for (i = 0; i < g->size; i++)
    {
      free(g->edges[i]);
    }
  free(g->edges);
  free(g->vertices);
  free(g);
}

void graph_add_edge_uni(graph g, int u, int v)
{
  if (u < g->size && v < g->size)
    g->edges[u][v] = 1;
}

void graph_add_edge_bi(graph g, int u, int v)
{
  graph_add_edge_uni(g, u, v);
  graph_add_edge_uni(g, v, u);
}

void graph_print_adjacent(graph g)
{
  int i, j;
  printf("adjacency list:\n");
  for (i = 0; i < g->size; i++)
    {
      printf("%d |", i);
      for (j = 0; j < g->size; j++)
        {
	  if (g->edges[i][j] == 1)
            {
	      printf(" %d", j);
            }
        }
      printf("\n");
    }
}

void graph_print_dist_pred(graph g)
{
  int i;
  printf("vertex distance pred\n");
  for (i = 0; i < g->size; i++)
    {
      printf("   %d        %d   %d\n", i, g->vertices[i].distance, g->vertices[i].predecessor);
    }
}

void graph_bfs(graph g, int source)
{
  int i;
  queue q;

  for (i = 0; i < g->size; i++)
    {
      g->vertices[i].state = UNVISITED;
      g->vertices[i].distance = -1;
      g->vertices[i].predecessor = -1;
    }

  g->vertices[source].state = VISITED_SELF;
  g->vertices[source].distance = 0;

  q = queue_new();
  enqueue(q, source);

  while (queue_size(q) != 0)
    {
      int u = dequeue(q);
      int v;
      for (v = 0; v < g->size; v++)
        {
	  if (g->vertices[v].state == UNVISITED)
            {
	      if (g->edges[u][v] == 1)
                {
		  g->vertices[v].state = VISITED_SELF;
		  g->vertices[v].distance = 1 + g->vertices[u].distance;
		  g->vertices[v].predecessor = u;
		  enqueue(q, v);
                }
            }
        }
      g->vertices[u].state = VISITED_DESCENDANTS;
    }

  queue_free(q);
}
