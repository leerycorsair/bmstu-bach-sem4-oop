#ifndef MODEL_H
#define MODEL_H

#include "edges.h"
#include "error.h"
#include "vertices.h"

typedef struct
{
  vertices_t vertices;
  point_t model_center;
  edges_t edges;
} model_t;

model_t &model_init(void);

error_t model_move(model_t &model, const move_t move_data);
error_t model_scale(model_t &model, const scale_t scale_data);
error_t model_rotate(model_t &model, const rotate_t rotate_data);
error_t model_load(model_t &model, const load_t load_data);
error_t model_render(const model_t &model, const render_t render);

void model_free(model_t &model);

#endif // MODEL_H
