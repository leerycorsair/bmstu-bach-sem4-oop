#ifndef __MOVE_MODEL_HPP__
#define __MOVE_MODEL_HPP__

#include <cstddef>
#include "../model_command.hpp"

class MoveModel : public ModelCommand
{
public:
    MoveModel() = delete;
    MoveModel(size_t model_id, double dx, double dy, double dz);
    ~MoveModel() override = default;
    void execute() override;

private:
    std::size_t model_id;
    double dx, dy, dz;
};

#endif //__MOVE_MODEL_HPP__
