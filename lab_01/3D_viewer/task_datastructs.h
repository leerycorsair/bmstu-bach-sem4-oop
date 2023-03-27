#ifndef TASK_DATASTRUCTS_H
#define TASK_DATASTRUCTS_H

#include <QGraphicsScene>

typedef struct
{
  int dx;
  int dy;
  int dz;
} move_t;

typedef struct
{
  double kx;
  double ky;
  double kz;
} scale_t;

typedef struct
{
  int x_angle;
  int y_angle;
  int z_angle;
} rotate_t;

typedef const char *string_literal;

typedef struct
{
  string_literal filename;
} load_t;

typedef struct
{
  QGraphicsScene *scene;
} render_t;

move_t move_data_init(const int dx, const int dy, const int dz);
scale_t scale_data_init(const double kx, const double ky, const double kz);
rotate_t rotate_data_init(const int x_angle, const int y_angle,
                          const int z_angle);
load_t load_data_init(string_literal str);
render_t render_data_init(QGraphicsScene *scene);

#endif // TASK_DATASTRUCTS_H
