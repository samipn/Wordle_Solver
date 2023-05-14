#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "graphsearch.h"

// dealing with sets of integers. We wrote these in class.
LLint *add_to_set(LLint *set, int val) {
  LLint *newfront = calloc(1, sizeof(LLint));
  newfront->val = val;
  newfront->next = set;

  return newfront;
}

bool set_contains(LLint *set, int val) {
  if (set == NULL) {
    return false;
  } else if (set->val == val) {
    return true;
  } else {
    return set_contains(set->next, val);
  }
}

// Linked lists of paths. You'll need to implement these.

// Returns the new front of the queue, for a queue of Path structs.
// Usually this will be the old front of the queue, but if q is NULL, then it
// will allocate a new linked list node and return that.
LLPath *enqueue_path(LLPath *q, Path path) {
  LLPath *new_node = calloc(1, sizeof(LLPath));
  new_node->val = path;
  if (q == NULL){
    return new_node; 
  }
  LLPath *current = q;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
  return q;
}

bool dequeue_path(LLPath **q, Path *ret) {
  if (*q == NULL) {
    return false;
  }
  *ret = (*q)->val;
  LLPath *free_variable = *q;
  *q = (*q)->next;
  free(free_variable);
  return true;
}

// We wrote these in class.
Graph *graph_create(int vertices) {
  Graph *g = (Graph *)malloc(sizeof(Graph));
  g->vertices = vertices;
  g->matrix = (int **)calloc(vertices, sizeof(int*));
  for (int i=0; i < vertices; i++) {
    g->matrix[i] = (int *)calloc(vertices, sizeof(int));
  }
  return g;
}

void graph_add_edge(Graph *g, int i, int j) {
  g->matrix[i][j] = 1;
}

bool graph_has_edge(Graph *g, int i, int j) {
  return g->matrix[i][j];
}

// Convenience method for you -- returns a new Path where you have added another
// vertex along the path.
Path path_extend(Path path, int new_vertex) {
  Path out;
  out.steps = path.steps;

  for (int i=0; i < path.steps; i++) {
    out.vertices_visited[i] = path.vertices_visited[i];
  }
  out.vertices_visited[path.steps] = new_vertex;
  out.steps += 1;
  return out;
}

// Print out a path nicely for the user.
void print_path(Path path) {
  if (path.steps == 0) {
    puts("(empty path)");
  }
  for (int i=0; i < path.steps; i++) {
    printf("%s%d",
        (i == 0) ? "" : " -> ",
        path.vertices_visited[i]);
  }
  puts("");
}

// Breadth-first search!
/*Path graph_find_path_bfs(Graph *g, int i, int j) {
  LLpath *visited = NULL;
  LLPath *to_visit = NULL;
  Path starting_path;
  starting_path.vertices_visited[0] = i;
  to_visit = enqueue_path(to_visit, starting_path);
  while (to_visit != NULL) {
    int current;
    Path current_path;
    current_path.vertices_visited[0] = current;
    dequeue_path(&to_visit, &current_path);
    if (current == j) {
      return visited->val;
    }
    visited = add_to_set(visited, current);
    for(int neighbor = 0; neighbor < g->vertices; neighbor++){
      if (graph_has_edge(g, current, neighbor) && !set_contains(visited, neighbor)){
        Path neighbor_path;
        neighbor_path.vertices_visited[0] = neighbor;
        to_visit = enqueue_path(to_visit, neighbor_path);
      }
    }
  Path empty = {0, {0}};
  return empty;
  }
  return 0;
}

 Depth-first search!
Path graph_find_path_dfs(Graph *g, int i, int j) {
   YOUR CODE HERE.

  Path empty = {0, {0}};
  return empty;
}
*/
