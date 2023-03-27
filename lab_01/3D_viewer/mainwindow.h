#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "action.h"
#include "config.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
  class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow(void);

private slots:
  void on_move_button_clicked(void);
  void on_scale_button_clicked(void);
  void on_load_button_clicked(void);
  void on_rotate_button_clicked(void);

private:
  void scene_create(void);
  void scene_delete(void);
  error_t render_perform(void);
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
