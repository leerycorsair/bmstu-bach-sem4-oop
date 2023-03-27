#include "vertices.h"

static error_t vertices_read_amount(vertices_t &vertices, FILE *f);
static error_t vertices_allocate(vertices_t &vertices);
static error_t vertices_read(vertices_t &vertices, FILE *f);

vertices_t vertices_init(void)
{
  vertices_t vertices;
  vertices.data = NULL;
  vertices.data_size = 0;
  return vertices;
}
error_t vertices_move(vertices_t &vertices, const move_t &move_data)
{
  error_t error_code = SUCCESS;
  if (vertices.data)
    for (size_t i = 0; i < vertices.data_size; i++)
      point_move(vertices.data[i], move_data);
  else
  {
    error_code = NO_POINTS;
  }
  return error_code;
}
error_t vertices_scale(vertices_t &vertices, const point_t &center,
                       const scale_t &scale_data)
{
  error_t error_code = SUCCESS;
  if (vertices.data)
    for (size_t i = 0; i < vertices.data_size; i++)
      point_scale(vertices.data[i], center, scale_data);
  else
  {
    error_code = NO_POINTS;
  }
  return error_code;
}
error_t vertices_rotate(vertices_t &vertices, const point_t &center,
                        const rotate_t &rotate_data)
{
  error_t error_code = SUCCESS;
  if (vertices.data)
    for (size_t i = 0; i < vertices.data_size; i++)
      point_rotate(vertices.data[i], center, rotate_data);
  else
  {
    error_code = NO_POINTS;
  }
  return error_code;
}
error_t vertices_process(vertices_t &vertices, FILE *f)
{
  error_t error_code = vertices_read_amount(vertices, f);
  if (error_code == SUCCESS)
  {
    error_code = vertices_allocate(vertices);
    if (error_code == SUCCESS)
    {
      error_code = vertices_read(vertices, f);
      if (error_code != SUCCESS)
        vertices_free(vertices);
    }
  }
  return error_code;
}

void vertices_free(vertices_t &vertices)
{
  if (vertices.data)
  {
    free(vertices.data);
    vertices.data_size = 0;
  }
}

static error_t vertices_read(vertices_t &vertices, FILE *f)
{
  error_t error_code = SUCCESS;
  for (size_t i = 0; i < vertices.data_size && error_code == SUCCESS; i++)
    error_code = point_read(vertices.data[i], f);
  return error_code;
}

static error_t vertices_allocate(vertices_t &vertices)
{
  error_t error_code;
  point_t *tmp = (point_t *)malloc(vertices.data_size * sizeof(point_t));
  if (tmp)
  {
    vertices.data = tmp;
    error_code = SUCCESS;
  }
  else
    error_code = UNSUCCESSFUL_MEMORY_ALLOCATION;
  return error_code;
}

static error_t vertices_read_amount(vertices_t &vertices, FILE *f)
{
  error_t error_code = SUCCESS;
  if (fscanf(f, "%zu", &vertices.data_size) != 1 || vertices.data_size < 2)
    error_code = VERTICES_SIZE_ERROR;
  return error_code;
}
