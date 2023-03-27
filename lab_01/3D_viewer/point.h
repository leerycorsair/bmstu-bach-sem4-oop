#ifndef POINT_H
#define POINT_H

#include "error.h"
#include "task_datastructs.h"
#include <stdio.h>

typedef struct
{
  double x;
  double y;
  double z;
} point_t;

point_t point_init();

void point_move(point_t &point, const move_t move_data);
void point_scale(point_t &point, const point_t &center,
                 const scale_t scale_data);
void point_rotate(point_t &point, const point_t &center,
                  const rotate_t rotate_data);

error_t point_read(point_t &point, FILE *f);

#endif // POINT_H
