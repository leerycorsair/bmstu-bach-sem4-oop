#ifndef EDGE_H
#define EDGE_H

#include "error.h"
#include "task_datastructs.h"
#include "vertices.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  size_t point1_index;
  size_t point2_index;
} edge_t;

error_t edge_read(edge_t &edge, FILE *f);
error_t edge_draw(const edge_t &edge, const vertices_t &vertices,
                  const render_t &render);

#endif // EDGE_H
