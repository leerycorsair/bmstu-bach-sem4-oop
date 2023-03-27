
#ifndef __REMOVE_MODEL_HPP__
#define __REMOVE_MODEL_HPP__

#include <cstddef>
#include "../model_command.hpp"

class RemoveModel : public ModelCommand
{
public:
    RemoveModel() = delete;
    explicit RemoveModel(std::size_t model_id);
    ~RemoveModel() override = default;
    void execute() override;

private:
    std::size_t model_id;
};

#endif //__REMOVE_MODEL_HPP__
