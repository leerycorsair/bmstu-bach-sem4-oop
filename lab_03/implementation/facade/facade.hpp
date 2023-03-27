#ifndef __FACADE_HPP__
#define __FACADE_HPP__

#include <memory>
#include "commands/command.hpp"

class Facade
{
public:
    void execute(const std::shared_ptr<Command> &command);
};

#endif //__FACADE_HPP__
