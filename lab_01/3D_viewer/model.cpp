#include "model.h"

static error_t model_read(model_t &model, FILE *f);

model_t &model_init(void)
{
  model_t model;
  model.vertices = vertices_init();
  model.model_center = point_init();
  model.edges = edges_init();
  return model;
}

error_t model_move(model_t &model, const move_t move_data)
{
  error_t error_code = SUCCESS;
  error_code = vertices_move(model.vertices, move_data);
  if (error_code == SUCCESS)
    point_move(model.model_center, move_data);
  return error_code;
}

error_t model_scale(model_t &model, const scale_t scale_data)
{
  error_t error_code = SUCCESS;
  error_code = vertices_scale(model.vertices, model.model_center, scale_data);
  return error_code;
}
error_t model_rotate(model_t &model, const rotate_t rotate_data)
{
  error_t error_code = SUCCESS;
  error_code = vertices_rotate(model.vertices, model.model_center, rotate_data);
  return error_code;
}

void model_free(model_t &model)
{
  edges_free(model.edges);
  vertices_free(model.vertices);
}

error_t model_load(model_t &model, const load_t load_data)
{
  error_t error_code = SUCCESS;
  FILE *f = fopen(load_data.filename, "r");
  if (f)
  {
    model_t tmp_model = model_init();
    error_code = model_read(tmp_model, f);
    fclose(f);
    if (error_code == SUCCESS)
    {
      model_free(model);
      model = tmp_model;
    }
  }
  else
    error_code = FILE_CANT_BE_OPENED;
  return error_code;
}

static error_t model_read(model_t &model, FILE *f)
{
  error_t error_code = SUCCESS;
  error_code = vertices_process(model.vertices, f);
  if (error_code == SUCCESS)
  {
    error_code = edges_process(model.edges, f);
    if (error_code != SUCCESS)
      vertices_free(model.vertices);
  }
  return error_code;
}

error_t model_render(const model_t &model, const render_t render)
{
  render.scene->clear();
  error_t error_code = edges_draw(model.edges, model.vertices, render);
  return error_code;
}
