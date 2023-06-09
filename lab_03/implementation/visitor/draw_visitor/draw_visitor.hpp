#ifndef __DRAW_VISITOR_HPP__
#define __DRAW_VISITOR_HPP__

#include <memory>
#include "objects/model/model_details/point/point.hpp"
#include "objects/camera/camera.hpp"
#include "objects/composite/composite.hpp"
#include "drawer/drawer.hpp"
#include "visitor/visitor.hpp"

class DrawVisitor : public Visitor
{
public:
    DrawVisitor(const std::shared_ptr<Drawer> &drawer, const std::shared_ptr<Camera> &camera);

    void visit(const Camera &camera) override;
    void visit(const Composite &composite) override;
    void visit(const Model &model) override;

private:
    std::shared_ptr<Drawer> drawer;
    std::shared_ptr<Camera> camera;

    Point projectPoint(const Point &point);
};

#endif //__DRAW_VISITOR_HPP__
