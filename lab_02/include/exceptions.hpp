#ifndef __EXCEPTIONS_HPP__
#define __EXCEPTIONS_HPP__

#include <exception>
#include <string>

class BaseException : public std::exception
{
public:
    BaseException(std::string filename,
                  const char *class_name,
                  std::string function,
                  int line_no,
                  std::string time,
                  std::string exc_info)
    {
        this->trace = "File: " + filename +
                      "Class:" + std::string(class_name) +
                      "Line:" + std::to_string(line_no) +
                      "Function:" + function +
                      "Time:" + time +
                      "Message:" + exc_info;
    }

    virtual const char *what() const noexcept override
    {
        std::string msg = trace + "\nBaseException: an unknown error occurred.";
        return msg.c_str();
    }

protected:
    std::string trace;
};

class IndexError : BaseException
{
public:
    IndexError(std::string filename,
               const char *class_name,
               std::string function,
               int line_no,
               std::string time,
               std::string exc_info) : BaseException(filename, class_name, function, line_no, time, exc_info){};

    virtual const char *what() const noexcept override
    {
        std::string msg = trace + "\nIndexError: an index out of range.";
        return msg.c_str();
    }
};

class MemoryError : BaseException
{
public:
    MemoryError(std::string filename,
                const char *class_name,
                std::string function,
                int line_no,
                std::string time,
                std::string exc_info) : BaseException(filename, class_name, function, line_no, time, exc_info){};

    virtual const char *what() const noexcept override
    {
        std::string msg = trace + "\nMemoryError: failed to allocate memory.";
        return msg.c_str();
    }
};

class PointerError : BaseException
{
public:
    PointerError(std::string filename,
                 const char *class_name,
                 std::string function,
                 int line_no,
                 std::string time,
                 std::string exc_info) : BaseException(filename, class_name, function, line_no, time, exc_info){};

    virtual const char *what() const noexcept override
    {
        std::string msg = trace + "\nPointerError: an invalid pointer.";
        return msg.c_str();
    }
};

class InitializationError : BaseException
{
public:
    InitializationError(std::string filename,
                        const char *class_name,
                        std::string function,
                        int line_no,
                        std::string time,
                        std::string exc_info) : BaseException(filename, class_name, function, line_no, time, exc_info){};

    virtual const char *what() const noexcept override
    {
        std::string msg = trace + "\nInitializationError: an invalid initializer list.";
        return msg.c_str();
    }
};

class IncorrectCMatrixError : BaseException
{
public:
    IncorrectCMatrixError(std::string filename,
                          const char *class_name,
                          std::string function,
                          int line_no,
                          std::string time,
                          std::string exc_info) : BaseException(filename, class_name, function, line_no, time, exc_info){};

    virtual const char *what() const noexcept override
    {
        std::string msg = trace + "\nIncorrectCMatrixError: an invalid CMatrix.";
        return msg.c_str();
    }
};

class DimensionsError : BaseException
{
public:
    DimensionsError(std::string filename,
                    const char *class_name,
                    std::string function,
                    int line_no,
                    std::string time,
                    std::string exc_info) : BaseException(filename, class_name, function, line_no, time, exc_info){};

    virtual const char *what() const noexcept override
    {
        std::string msg = trace + "\nDimensionsError: invalid matrix dimensions.";
        return msg.c_str();
    }
};

class MatrixSquareError : BaseException
{
public:
    MatrixSquareError(std::string filename,
                      const char *class_name,
                      std::string function,
                      int line_no,
                      std::string time,
                      std::string exc_info) : BaseException(filename, class_name, function, line_no, time, exc_info){};

    virtual const char *what() const noexcept override
    {
        std::string msg = trace + "\nMatrixSquareError: matrix must be square.";
        return msg.c_str();
    }
};

class MatrixSingularError : BaseException
{
public:
    MatrixSingularError(std::string filename,
                        const char *class_name,
                        std::string function,
                        int line_no,
                        std::string time,
                        std::string exc_info) : BaseException(filename, class_name, function, line_no, time, exc_info){};

    virtual const char *what() const noexcept override
    {
        std::string msg = trace + "\nMatrixSingularError: matrix can not be singular.";
        return msg.c_str();
    }
};

class MatrixUnmatchError : BaseException
{
public:
    MatrixUnmatchError(std::string filename,
                       const char *class_name,
                       std::string function,
                       int line_no,
                       std::string time,
                       std::string exc_info) : BaseException(filename, class_name, function, line_no, time, exc_info){};

    virtual const char *what() const noexcept override
    {
        std::string msg = trace + "\nMatrixUnmatchError: matricies must correct dimensions.";
        return msg.c_str();
    }
};

class ZeroDivisionError : BaseException
{
public:
    ZeroDivisionError(std::string filename,
                      const char *class_name,
                      std::string function,
                      int line_no,
                      std::string time,
                      std::string exc_info) : BaseException(filename, class_name, function, line_no, time, exc_info){};

    virtual const char *what() const noexcept override
    {
        std::string msg = trace + "\nZeroDivisionError: division by zero.";
        return msg.c_str();
    }
};

#endif // __EXCEPTIONS_HPP__