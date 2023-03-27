#include "edges.h"

static error_t edges_read(edges_t &edges, FILE *f);
static error_t edges_allocate(edges_t &edges);
static error_t edges_read_amount(edges_t &edges, FILE *f);

edges_t edges_init()
{
  edges_t edges;
  edges.data = NULL;
  edges.data_size = 0;
  return edges;
}

void edges_free(edges_t &edges)
{
  if (edges.data)
  {
    free(edges.data);
    edges.data_size = 0;
  }
}

error_t edges_process(edges_t &edges, FILE *f)
{
  error_t error_code = edges_read_amount(edges, f);
  if (error_code == SUCCESS)
  {
    error_code = edges_allocate(edges);
    if (error_code == SUCCESS)
    {
      error_code = edges_read(edges, f);
      if (error_code != SUCCESS)
        edges_free(edges);
    }
  }
  return error_code;
}
error_t edges_draw(const edges_t &edges, const vertices_t &vertices,
                   const render_t &render)
{
  error_t error_code = SUCCESS;
  for (size_t i = 0; i < edges.data_size && error_code == SUCCESS; i++)
    error_code = edge_draw(edges.data[i], vertices, render);
  return error_code;
}

static error_t edges_read(edges_t &edges, FILE *f)
{
  error_t error_code = SUCCESS;
  for (size_t i = 0; i < edges.data_size && error_code == SUCCESS; i++)
    error_code = edge_read(edges.data[i], f);
  return error_code;
}

static error_t edges_allocate(edges_t &edges)
{
  error_t error_code;
  edge_t *tmp = (edge_t *)malloc(edges.data_size * sizeof(edge_t));
  if (tmp)
  {
    edges.data = tmp;
    error_code = SUCCESS;
  }
  else
    error_code = UNSUCCESSFUL_MEMORY_ALLOCATION;
  return error_code;
}

static error_t edges_read_amount(edges_t &edges, FILE *f)
{
  error_t error_code = SUCCESS;
  if (fscanf(f, "%zu", &edges.data_size) != 1 || edges.data_size < 2)
    error_code = EDGES_SIZE_ERROR;
  return error_code;
}
