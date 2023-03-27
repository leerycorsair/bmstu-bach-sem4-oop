
#ifndef __CAMERA_EXCEPTIONS_HPP__
#define __CAMERA_EXCEPTIONS_HPP__

class LastCameraRemoveError : public BaseException
{
public:
    explicit LastCameraRemoveError(const string &file, const int line, const string &msg) : BaseException(file, line, msg)
    {
        this->error_msg = "LastCameraRemoveError: " + this->error_msg;
    }
};

#endif //__CAMERA_EXCEPTIONS_HPP__
