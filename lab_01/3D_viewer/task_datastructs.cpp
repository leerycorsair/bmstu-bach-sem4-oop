#include "task_datastructs.h"

move_t move_data_init(const int dx, const int dy, const int dz)
{
  move_t move_data;
  move_data.dx = dx;
  move_data.dy = dy;
  move_data.dz = dz;
  return move_data;
}

scale_t scale_data_init(const double kx, const double ky, const double kz)
{
  scale_t scale_data;
  scale_data.kx = kx;
  scale_data.ky = ky;
  scale_data.kz = kz;
  return scale_data;
}

rotate_t rotate_data_init(const int x_angle, const int y_angle,
                          const int z_angle)
{
  rotate_t rotate_data;
  rotate_data.x_angle = x_angle;
  rotate_data.y_angle = y_angle;
  rotate_data.z_angle = z_angle;
  return rotate_data;
}

load_t load_data_init(string_literal str)
{
  load_t load_data;
  load_data.filename = str;
  return load_data;
}

render_t render_data_init(QGraphicsScene *scene)
{
  render_t render;
  render.scene = scene;
  return render;
}
