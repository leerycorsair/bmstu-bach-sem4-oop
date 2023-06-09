
#ifndef __MODEL_EXCEPTIONS_HPP__
#define __MODEL_EXCEPTIONS_HPP__

#include "base_exception.hpp"

class ModelError : public BaseException
{
public:
    explicit ModelError(const string &file, const int line, const string &msg) : BaseException(file, line, msg)
    {
        this->error_msg = "ModelError: " + this->error_msg;
    }
};

class NoModelError : public BaseException
{
public:
    explicit NoModelError(const string &file, const int line, const string &msg) : BaseException(file, line, msg)
    {
        this->error_msg = "NoModelError: " + this->error_msg;
    }
};

class EdgeError : public BaseException
{
public:
    explicit EdgeError(const string &file, const int line, const string &msg) : BaseException(file, line, msg)
    {
        this->error_msg = "EdgeError: " + this->error_msg;
    }
};

#endif //__MODEL_EXCEPTIONS_HPP__
