#ifndef __SCALE_MODEL_HPP__
#define __SCALE_MODEL_HPP__

#include <cstddef>
#include "../model_command.hpp"

class ScaleModel : public ModelCommand
{
public:
    ScaleModel() = delete;
    ScaleModel(std::size_t model_id, double kx, double ky, double kz);
    ~ScaleModel() override = default;
    void execute() override;

private:
    std::size_t model_id;
    double kx, ky, kz;
};

#endif //__SCALE_MODEL_HPP__
