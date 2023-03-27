#ifndef __LOAD_CAMERA_HPP__
#define __LOAD_CAMERA_HPP__

#include <commands/camera/camera_command.hpp>
#include <string>

class LoadCamera : public CameraCommand
{
public:
    explicit LoadCamera(std::string filename);
    void execute() override;

private:
    std::string filename;
};

#endif //__LOAD_CAMERA_HPP__
