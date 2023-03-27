
#ifndef __QT_DRAWER_FACTORY_HPP__
#define __QT_DRAWER_FACTORY_HPP__

#include <memory>
#include <QGraphicsScene>

#include "drawer/drawer.hpp"

class QtDrawerFactory : public DrawerFactory
{
public:
    explicit QtDrawerFactory(std::shared_ptr<QGraphicsScene> &scene);
    std::unique_ptr<Drawer> createDrawer() override;

private:
    std::shared_ptr<QGraphicsScene> scene;
};

#endif //__QT_DRAWER_FACTORY_HPP__
