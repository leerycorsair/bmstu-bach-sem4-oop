#include <QDebug>
#include "doors.h"
#include <stdio.h>

Doors::Doors(QObject *parent) : QObject(parent)
{
    stay_timer.setInterval(STAY_TIME);
    stay_timer.setSingleShot(true);
    closing_timer.setSingleShot(true);
    opening_timer.setSingleShot(true);

    QObject::connect(&closing_timer, SIGNAL(timeout()), this, SLOT(closed()));
    QObject::connect(&opening_timer, SIGNAL(timeout()), this, SLOT(opened()));
    QObject::connect(&stay_timer, SIGNAL(timeout()), this, SLOT(closing()));
    QObject::connect(this, SIGNAL(doors_opened()), &stay_timer, SLOT(start()));
}

void Doors::closing()
{
    if (state != OPENED)
        return;

    qDebug() << "Двери закрываются.";
    state = CLOSING;
    closing_timer.start(CLOSING_TIME);
}

void Doors::opening()
{
    if (state != CLOSED && state != CLOSING)
        return;

    qDebug() << "Двери открываются.";
    if (state == CLOSED)
    {
        state = OPENING;
        opening_timer.start(OPENING_TIME);
    }
    else if (state == CLOSING)
    {
        state = OPENING;
        int rem_time = closing_timer.remainingTime();
        closing_timer.stop();
        opening_timer.start(OPENING_TIME - rem_time);
    }
}

void Doors::closed()
{
    if (state != CLOSING)
        return;

    qDebug() << "Двери закрыты.";
    state = CLOSED;
    emit doors_closed();
}

void Doors::opened()
{
    if (state != OPENING)
        return;

    qDebug() << "Двери открыты.";
    state = OPENED;
    emit doors_opened();
}
