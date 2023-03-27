#include "point.h"
#include <math.h>

static void point_xrotate(point_t &point, const point_t &center,
                          const int x_angle);
static void point_yrotate(point_t &point, const point_t &center,
                          const int y_angle);
static void point_zrotate(point_t &point, const point_t &center,
                          const int z_angle);
static double deg_to_rad(const int deg);
static void point_move_to_coord_center(point_t &point, const point_t &center);
static void point_move_from_coord_center(point_t &point, const point_t &center);
static void point_inverse(point_t &point);

point_t point_init()
{
  point_t point;
  point.x = 0;
  point.y = 0;
  point.z = 0;
  return point;
}

void point_move(point_t &point, const move_t move_data)
{
  point.x += move_data.dx;
  point.y += move_data.dy;
  point.z += move_data.dz;
}

void point_scale(point_t &point, const point_t &center,
                 const scale_t scale_data)
{
  point.x = point.x * scale_data.kx + (1 - scale_data.kx) * center.x;
  point.y = point.y * scale_data.ky + (1 - scale_data.ky) * center.y;
  point.z = point.z * scale_data.kz + (1 - scale_data.kz) * center.z;
}

void point_rotate(point_t &point, const point_t &center,
                  const rotate_t rotate_data)
{
  point_move_to_coord_center(point, center);
  point_xrotate(point, center, rotate_data.x_angle);
  point_yrotate(point, center, rotate_data.y_angle);
  point_zrotate(point, center, rotate_data.z_angle);
  point_move_from_coord_center(point, center);
}

error_t point_read(point_t &point, FILE *f)
{
  error_t error_code = SUCCESS;
  if (fscanf(f, "%lf %lf %lf", &point.x, &point.y, &point.z) != 3)
    error_code = INCORRECT_FILE;
  return error_code;
}

static void point_xrotate(point_t &point, const point_t &center,
                          const int x_angle)
{
  double cos_value = cos(deg_to_rad(x_angle));
  double sin_value = sin(deg_to_rad(x_angle));
  double buf_y = point.y;
  point.y = point.y * cos_value - point.z * sin_value;
  point.z = buf_y * sin_value + point.z * cos_value;
}
static void point_yrotate(point_t &point, const point_t &center,
                          const int y_angle)
{
  double cos_value = cos(deg_to_rad(y_angle));
  double sin_value = sin(deg_to_rad(y_angle));
  double buf_x = point.x;
  point.x = point.x * cos_value - point.z * sin_value;
  point.z = buf_x * sin_value + point.z * cos_value;
}
static void point_zrotate(point_t &point, const point_t &center,
                          const int z_angle)
{
  double cos_value = cos(deg_to_rad(z_angle));
  double sin_value = sin(deg_to_rad(z_angle));
  double buf_x = point.x;
  point.x = point.x * cos_value - point.y * sin_value;
  point.y = buf_x * sin_value + point.y * cos_value;
}

static void point_move_to_coord_center(point_t &point, const point_t &center)
{
  point_t delta_point = center;
  point_inverse(delta_point);
  point_move(point, center);
}

static void point_move_from_coord_center(point_t &point, const point_t &center)
{
  point_t delta_point = center;
  point_move(point, center);
}

static void point_inverse(point_t &point)
{
  point.x *= -1;
  point.y *= -1;
  point.z *= -1;
}

static double deg_to_rad(const int deg) { return (double)deg * M_PI / 180; }
