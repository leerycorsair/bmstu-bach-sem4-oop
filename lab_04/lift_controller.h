#ifndef LIFT_CONTROLLER_H
#define LIFT_CONTROLLER_H

#include "direction.h"
#include <QObject>
#include <vector>

#define FLOOR_NUMBER 20

class LiftController : public QObject
{
    Q_OBJECT

    enum state_t
    {
        FREE,
        BUSY
    };

public:
    explicit LiftController(QObject *parent = nullptr);
    void new_target(int floor);

public slots:
    void free(int floor);
    void busy(int floor, const direction_t &dir);

signals:
    void controller_new_target(int floor, const direction_t &dir);

private:
    direction_t current_direction = STAY;
    int current_floor = 1;
    int current_target = 0;
    state_t state = FREE;

    void next_target();

    std::vector<bool> targets;
};

#endif // LIFT_CONTROLLER_H
