
#ifndef __MOVE_CAMERA_HPP__
#define __MOVE_CAMERA_HPP__

#include <cstddef>
#include "../camera_command.hpp"

class MoveCamera : public CameraCommand
{
public:
    MoveCamera() = delete;
    MoveCamera(std::size_t camera_id, double shift_x, double shift_y);
    ~MoveCamera() override = default;
    void execute() override;

private:
    std::size_t camera_id;
    double shift_x, shift_y;
};

#endif //__MOVE_CAMERA_HPP__
