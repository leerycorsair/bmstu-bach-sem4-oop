

#ifndef __UI_EXCEPTIONS_HPP__
#define __UI_EXCEPTIONS_HPP__

#include "base_exception.hpp"

class UIError : public BaseException
{
public:
    explicit UIError(const string &file, const int line, const string &msg) : BaseException(file, line, msg)
    {
        this->error_msg = "UIError: " + this->error_msg;
    }
};

#endif //__UI_EXCEPTIONS_HPP__
