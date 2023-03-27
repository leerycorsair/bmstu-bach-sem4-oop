#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QTimer>

#define STAY_TIME 2000
#define CLOSING_TIME 2000
#define OPENING_TIME 2000

class Doors : public QObject
{
    Q_OBJECT
    enum state_t
    {
        CLOSED,
        OPENING,
        OPENED,
        CLOSING
    };

public:
    explicit Doors(QObject *parent = nullptr);

signals:
    void doors_closed();
    void doors_opened();

public slots:
    void closing();
    void opening();
    void closed();
    void opened();

private:
    state_t state = CLOSED;
    QTimer opening_timer;
    QTimer stay_timer;
    QTimer closing_timer;
};

#endif // DOORS_H
