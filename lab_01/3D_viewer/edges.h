#ifndef EDGES_H
#define EDGES_H

#include "edge.h"

typedef struct
{
  edge_t *data;
  size_t data_size;
} edges_t;

edges_t edges_init();
error_t edges_process(edges_t &edges, FILE *f);
error_t edges_draw(const edges_t &edges, const vertices_t &vertices,
                   const render_t &render);
void edges_free(edges_t &edges);

#endif // EDGES_H
