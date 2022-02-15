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
  LLPath *newnode = calloc(1, sizeof(LLPath));
  newnode->val = path;

  if (q == NULL) {
    return newnode;
  }

  LLPath *cur = q;
  while(cur->next != NULL) {
    cur = cur->next;
  }
  cur->next = newnode;
  return q;

}

bool dequeue_path(LLPath **q, Path *ret) {
  if (*q == NULL) {
    return false;
  }

  *ret = (*q)->val;
  
  LLPath *freethis = *q;
  *q = (*q)->next;
  free(freethis);
  return true;

}

LLPath *push(LLPath *s, Path x ) {
  LLPath *newnode = calloc(1, sizeof(LLPath));
  if (s == NULL) {
    newnode->val = x;
    newnode->next = s;
    return newnode;
  }
  newnode->val = x;
  newnode->next = s;
  return newnode;
}

bool pop(LLPath **s, Path *y) {
  if (*s == NULL) {
    return false;
  }

  *y = (*s)->val;
  
  LLPath *deletethis = *s;
  *s = (*s)->next;
  free(deletethis);
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

void graph_destroy(Graph **g) {
  
}

// Breadth-first search!
Path graph_find_path_bfs(Graph *g, int i, int j) {
  LLint *visited = NULL;
  LLPath *to_visit = NULL;
  Path empty = {0, {0}};
  Path starting = {1, {i}};

  to_visit = enqueue_path(to_visit, starting);

  while(to_visit != NULL) {
    Path current;
    dequeue_path(&to_visit, &current);

    int recent = current.vertices_visited[current.steps - 1];

    if (recent == j) {
      return current;
    }
    

    visited = add_to_set(visited, recent);

    // find all of the neighbors of the current node
    for(int neighbor = 0; neighbor < g->vertices; neighbor++) {
      if (graph_has_edge(g, recent, neighbor) &&
          !set_contains(visited, neighbor)) {
        to_visit = enqueue_path(to_visit, path_extend(current, neighbor));
      }
    }
    current.steps = current.steps + 1;
  }
  return empty;
}


// Depth-first search!
Path graph_find_path_dfs(Graph *g, int i, int j) {
  LLint *visited = NULL;
  LLPath *to_visit = NULL;
  Path starting = {1, {i}};
  Path empty = {0, {0}};

  to_visit = push(to_visit, starting);

  while(to_visit != NULL) {
    Path current;
    pop(&to_visit, &current);

    int recent = current.vertices_visited[current.steps - 1];

    if (recent == j) {
      return current;
    }
    
    visited = add_to_set(visited, recent);

    // find all of the neighbors of the current node
    for(int neighbor = g->vertices - 1; neighbor > 0; neighbor--) {
      if (graph_has_edge(g, recent, neighbor) &&
          !set_contains(visited, neighbor)) {
        to_visit = push(to_visit, path_extend(current, neighbor));
      }
    }
    current.steps = current.steps + 1;
  }
  return empty;
}

