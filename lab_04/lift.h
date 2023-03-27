#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include "lift_cabin.h"
#include "lift_controller.h"

class Lift : public QObject
{
    Q_OBJECT

public:
    explicit Lift(QObject *parent = nullptr);

public slots:
    void call_button_pressed(int floor);

private:
    LiftCabin cabin;
    LiftController control_panel;
};

#endif // LIFT_H
