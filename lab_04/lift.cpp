#include "lift.h"

Lift::Lift(QObject *parent) : QObject(parent)
{
    QObject::connect(&cabin, SIGNAL(cabin_wait(int)), &control_panel, SLOT(free(int)));
    QObject::connect(&cabin, SIGNAL(cabin_passed_floor(int, direction_t)), &control_panel, SLOT(busy(int, direction_t)));
    QObject::connect(&control_panel, SIGNAL(controller_new_target(int, direction_t)), &cabin, SLOT(get_target(int, direction_t)));
}

void Lift::call_button_pressed(int floor)
{
    control_panel.new_target(floor);
}
