
#ifndef __LOAD_MODEL_HPP__
#define __LOAD_MODEL_HPP__

#include <string>
#include "../model_command.hpp"

class LoadModel : public ModelCommand
{
public:
    LoadModel() = delete;
    explicit LoadModel(std::string filename);
    ~LoadModel() override = default;
    void execute() override;

private:
    std::string filename;
};

#endif //__LOAD_MODEL_HPP__
