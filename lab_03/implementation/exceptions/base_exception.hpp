#ifndef __BASE_EXCEPTION_HPP__
#define __BASE_EXCEPTION_HPP__

#include <exception>
#include <string>
#include <ctime>

using string = std::string;

class BaseException : public std::exception
{
protected:
    string error_msg;

public:
    BaseException(const string &file, const int line, const string &err_msg = "No error message")
    {
        time_t curr_time = time(nullptr);
        auto local_time = localtime(&curr_time);
        this->error_msg =
            err_msg + "\nFile: " + file + "\nLine: " + std::to_string(line) + "\nTime: " + asctime(local_time);
    }

    const char *what() const noexcept override
    {
        return this->error_msg.c_str();
    }
};

#endif //__BASE_EXCEPTION_HPP__
