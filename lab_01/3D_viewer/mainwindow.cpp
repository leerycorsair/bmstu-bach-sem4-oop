#include "mainwindow.h"
#include "ui_mainwindow.h"

QGraphicsScene *scene;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  this->scene_create();
}

MainWindow::~MainWindow(void)
{
  action_t action;
  action.task = EXIT;
  action_process(action);
  this->scene_delete();
  delete ui;
}

void MainWindow::scene_create(void)
{
  scene = new QGraphicsScene(this);
  ui->graphicsView->setScene(scene);
  ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->graphicsView->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
  int height = ui->graphicsView->height();
  int width = ui->graphicsView->width();
  scene->setSceneRect(-width / 2, -height / 2, width, height);
}

void MainWindow::scene_delete(void) { delete scene; }

void MainWindow::on_move_button_clicked(void)
{
  int dx = ui->dx_spinbox->value();
  int dy = ui->dy_spinbox->value();
  int dz = ui->dz_spinbox->value();
  action_t action;
  action.task = MOVE_MODEL;
  action.move_data = move_data_init(dx, dy, dz);
  error_t error_code = action_process(action);
  if (error_code != SUCCESS)
    error_show_info(error_code);
  else
  {
    error_code = render_perform();
    if (error_code != SUCCESS)
      error_show_info(error_code);
  }
}

void MainWindow::on_scale_button_clicked(void)
{
  double kx = ui->kx_dspinbox->value();
  double ky = ui->ky_dspinbox->value();
  double kz = ui->kz_dspinbox->value();
  action_t action;
  action.task = SCALE_MODEL;
  action.scale_data = scale_data_init(kx, ky, kz);
  error_t error_code = action_process(action);
  if (error_code != SUCCESS)
    error_show_info(error_code);
  else
  {
    error_code = render_perform();
    if (error_code != SUCCESS)
      error_show_info(error_code);
  }
}

void MainWindow::on_load_button_clicked(void)
{
  string_literal filename = MODEL_FILE;
  action_t action;
  action.task = LOAD_MODEL;
  action.load_data = load_data_init(filename);
  error_t error_code = action_process(action);
  if (error_code != SUCCESS)
    error_show_info(error_code);
  else
  {
    error_code = render_perform();
    if (error_code != SUCCESS)
      error_show_info(error_code);
  }
}

void MainWindow::on_rotate_button_clicked(void)
{
  int x_a = ui->xa_spinbox->value();
  int y_a = ui->ya_spinbox->value();
  int z_a = ui->za_spinbox->value();
  action_t action;
  action.task = MOVE_MODEL;
  action.rotate_data = rotate_data_init(x_a, y_a, z_a);
  error_t error_code = action_process(action);
  if (error_code != SUCCESS)
    error_show_info(error_code);
  else
  {
    error_code = render_perform();
    if (error_code != SUCCESS)
      error_show_info(error_code);
  }
}

error_t MainWindow::render_perform(void)
{
  action_t action;
  action.task = RENDER_MODEL;
  action.render = render_data_init(ui->graphicsView->scene());
  error_t error_code = action_process(action);
  return error_code;
}
