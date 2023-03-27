#ifndef __QT_DRAWER_HPP__
#define __QT_DRAWER_HPP__

#include "drawer/drawer.hpp"
#include <QGraphicsScene>
#include <memory>

class QtDrawer : public Drawer
{
public:
    QtDrawer() = delete;
    explicit QtDrawer(std::shared_ptr<QGraphicsScene> &scene);
    QtDrawer(const QtDrawer &drawer);
    void drawLine(const Point &point1, const Point &point2) override;
    void clearScene() override;

private:
    std::shared_ptr<QGraphicsScene> scene;
};

#endif //__QT_DRAWER_HPP__
