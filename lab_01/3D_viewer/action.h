#ifndef ACTION_H
#define ACTION_H

#include "model.h"

enum task_t
{
  MOVE_MODEL,
  SCALE_MODEL,
  ROTATE_MODEL,
  LOAD_MODEL,
  RENDER_MODEL,
  EXIT
};

typedef struct
{
  task_t task;
  move_t move_data;
  scale_t scale_data;
  rotate_t rotate_data;
  load_t load_data;
  render_t render;
} action_t;

error_t action_process(const action_t &action);

#endif // ACTION_H
