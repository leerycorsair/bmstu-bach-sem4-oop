
#include "edge.h"

static void edge_get_points(point_t *edge_points, const edge_t &edge,
                            const vertices_t &vertices);
static void draw_line(const point_t &point1, const point_t &point2, const render_t &render);

error_t edge_read(edge_t &edge, FILE *f)
{
  error_t error_code = SUCCESS;
  if (fscanf(f, "%zu %zu", &edge.point1_index, &edge.point2_index) != 2)
    error_code = INCORRECT_FILE;
  return error_code;
}

error_t edge_draw(const edge_t &edge, const vertices_t &vertices,
                  const render_t &render)
{
  error_t error_code = SUCCESS;
  point_t edge_points[2] = {};
  edge_get_points(edge_points, edge, vertices);
  draw_line(edge_points[0], edge_points[1], render);
  return error_code;
}

static void edge_get_points(point_t *edge_points, const edge_t &edge,
                            const vertices_t &vertices)
{
  edge_points[0] = vertices.data[edge.point1_index];
  edge_points[1] = vertices.data[edge.point2_index];
}

static void draw_line(const point_t &point1, const point_t &point2, const render_t &render)
{
  render.scene->addLine(point1.x, point1.y, point2.x, point2.y);
}