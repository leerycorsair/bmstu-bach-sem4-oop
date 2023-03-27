#ifndef VERTICES_H
#define VERTICES_H

#include "error.h"
#include "point.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  point_t *data;
  size_t data_size;
} vertices_t;

void vertices_free(vertices_t &vertices);

vertices_t vertices_init(void);

error_t vertices_move(vertices_t &vertices, const move_t &move_data);
error_t vertices_scale(vertices_t &vertices, const point_t &center,
                       const scale_t &scale_data);
error_t vertices_rotate(vertices_t &vertices, const point_t &center,
                        const rotate_t &rotate_data);
error_t vertices_process(vertices_t &vertices, FILE *f);

#endif // VERTICES_H
