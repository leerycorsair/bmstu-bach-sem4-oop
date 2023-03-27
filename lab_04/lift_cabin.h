#ifndef LIFT_CABIN_H
#define LIFT_CABIN_H

#include <QObject>
#include <QTimer>
#include "doors.h"
#include "direction.h"

#define MOVEMENT_TIME 2000

class LiftCabin : public QObject
{
    Q_OBJECT

    enum state_t
    {
        STOP,
        WAITING,
        START_MOVEMENT,
        MOVEMENT
    };

public:
    explicit LiftCabin(QObject *parent = nullptr);

signals:
    void cabin_called();
    void cabin_stopped();
    void cabin_target_achieved(int floor);
    void cabin_passed_floor(int floor, const direction_t &dir);
    void cabin_wait(int floor);

public slots:
    void stop();
    void wait();
    void get_target(int floor, const direction_t &dir);
    void movement();

private:
    Doors doors;
    direction_t current_direction = STAY;
    state_t state = WAITING;
    int current_floor = 1;
    int current_target = 0;

    QTimer movement_timer;
};

#endif // LIFT_CABIN_H
