#include <QDebug>
#include "lift_cabin.h"
#include <stdio.h>

LiftCabin::LiftCabin(QObject *parent) : QObject(parent)
{
    movement_timer.setSingleShot(true);
    QObject::connect(this, SIGNAL(cabin_called()), this, SLOT(movement()));
    QObject::connect(this, SIGNAL(cabin_stopped()), &doors, SLOT(opening()));
    QObject::connect(this, SIGNAL(cabin_target_achieved(int)), this, SLOT(stop()));
    QObject::connect(&doors, SIGNAL(doors_closed()), this, SLOT(wait()));
    QObject::connect(&movement_timer, SIGNAL(timeout()), this, SLOT(movement()));
}

void LiftCabin::stop()
{
    if (state != MOVEMENT)
        return;

    state = STOP;
    qDebug() << "Остановка:" << current_floor <<".";
    emit cabin_stopped();
}

void LiftCabin::wait()
{
    if (state != STOP)
        return;

    state = WAITING;
    qDebug() << "В ожидании.";
    emit cabin_wait(current_floor);
}

void LiftCabin::movement()
{
    if (state != START_MOVEMENT && state != MOVEMENT)
        return;

    if (state == MOVEMENT)
        current_floor += current_direction;

    state = MOVEMENT;
    if (current_floor == current_target)
        emit cabin_target_achieved(current_floor);
    else
    {
        emit cabin_passed_floor(current_floor, current_direction);
        movement_timer.start(MOVEMENT_TIME);
    }
}

void LiftCabin::get_target(int floor, const direction_t &dir)
{
    if (state != WAITING)
        return;

    state = START_MOVEMENT;
    current_target = floor;
    current_direction = dir;
    emit cabin_called();
}
