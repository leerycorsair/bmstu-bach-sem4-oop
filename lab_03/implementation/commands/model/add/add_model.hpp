#ifndef __ADD_MODEL_HPP__
#define __ADD_MODEL_HPP__

#include <memory>
#include <objects/object.hpp>
#include "../model_command.hpp"

class AddModel : public ModelCommand
{
public:
    AddModel() = delete;
    explicit AddModel(std::shared_ptr<Object> model);
    ~AddModel() override = default;
    void execute() override;

private:
    std::shared_ptr<Object> model;
};

#endif //__ADD_MODEL_HPP__
