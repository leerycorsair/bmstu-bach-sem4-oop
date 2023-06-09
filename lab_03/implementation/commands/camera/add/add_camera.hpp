
#ifndef __ADD_CAMERA_HPP__
#define __ADD_CAMERA_HPP__

#include "../camera_command.hpp"

class AddCamera : public CameraCommand
{
public:
    AddCamera() = delete;
    AddCamera(double x_pos, double y_pos, double z_pos);
    ~AddCamera() override = default;
    void execute() override;

private:
    double x_pos, y_pos, z_pos;
};

#endif //__ADD_CAMERA_HPP__
