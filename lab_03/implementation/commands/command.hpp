#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

class Command
{
public:
    Command() = default;
    virtual ~Command() = default;
    virtual void execute() = 0;
};

#endif //__COMMAND_HPP__
