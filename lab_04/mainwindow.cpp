#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setbuf(stdout, NULL);
    for (int i = 0; i < (int)(ui->floor_buttons.size()); ++i)
        connect(ui->floor_buttons[i], &QPushButton::pressed, this, [i, this]()
                { on_button_clicked(i + 1); });
}

void MainWindow::on_button_clicked(const int btn_number)
{
    lift.call_button_pressed(btn_number);
}

MainWindow::~MainWindow()
{
    delete ui;
}
