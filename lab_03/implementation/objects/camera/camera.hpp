
#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include "objects/object.hpp"
#include "objects/model/model_details/point/point.hpp"
#include "visitor/draw_visitor/draw_visitor.hpp"

class Camera : public InvisibleObject
{
public:
    friend class DrawVisitor;
    Camera() = default;
    explicit Camera(const Point &position);
    ~Camera() override = default;
    void transform(const Point &move_params, const Point &scale_params, const Point &rotate_params) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

private:
    Point position;
    void shiftX(double delta);
    void shiftY(double delta);
    void shiftZ(double delta);
    Point getPosition() const;
};

#endif //__CAMERA_HPP__
