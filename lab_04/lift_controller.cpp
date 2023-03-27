#include <QDebug>
#include "lift_controller.h"
#include <stdio.h>

LiftController::LiftController(QObject *parent)
    : QObject(parent)
{
    targets.resize(FLOOR_NUMBER);
    for (auto i : targets)
        i = false;
    QObject::connect(this, SIGNAL(controller_new_target(int, direction_t)),
                     this, SLOT(busy(int, direction_t)));
}

void LiftController::busy(int floor, const direction_t &dir)
{
    if (state == FREE)
    {
        state = BUSY;
        current_target = floor;
        current_direction = dir;
    }
    else if (state == BUSY)
    {
        qDebug() << "Этаж:" << floor << ".";
        current_floor += current_direction;
    }
}

void LiftController::free(int floor)
{
    state = FREE;
    current_floor = floor;
    next_target();
}

void LiftController::next_target()
{
    if (targets[current_floor - 1])
    {
        targets[current_floor - 1] = false;
        emit controller_new_target(current_floor, STAY);
    }
    else
    {
        int i = 0;
        while (i < (int)(targets.size()) && !targets[i])
            i++;
        if (i < (int)(targets.size()))
        {
            targets[i] = false;
            if (i > current_floor - 1) 
                emit controller_new_target(i + 1, UP);
            else
                emit controller_new_target(i + 1, DOWN);
        }
    }
}

void LiftController::new_target(int floor)
{
    qDebug() << "Новая цель:" << floor << ".";
    targets[floor - 1] = true;
    if (state == FREE)
        next_target();
}
