#ifndef __ROTATE_MODEL_HPP__
#define __ROTATE_MODEL_HPP__

#include <cstddef>
#include "../model_command.hpp"

class RotateModel : public ModelCommand
{
public:
    RotateModel() = delete;
    RotateModel(std::size_t model_id, double ax, double ay, double az);
    ~RotateModel() override = default;
    void execute() override;

private:
    std::size_t model_id;

    double ax, ay, az;
};

#endif //__ROTATE_MODEL_HPP__
