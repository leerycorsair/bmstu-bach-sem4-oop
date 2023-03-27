#ifndef __MATRIX_BASE_HPP__
#define __MATRIX_BASE_HPP__

#include <memory>
#include <stddef.h>

class MatrixBase
{
public:
    MatrixBase(const size_t rows, const size_t columns)
    {
        this->rows = alloc_size(rows);
        this->columns = alloc_size(columns);
    }

    virtual size_t get_columns() const
    {
        return bool(this->columns) ? *(this->columns) : 0;
    }

    virtual size_t get_rows() const
    {
        return bool(this->rows) ? *(this->rows) : 0;
    }

    virtual operator bool() const
    {
        return *(this->columns) && *(this->rows);
    }

    virtual ~MatrixBase() = 0;

protected:
    std::shared_ptr<size_t> rows;
    std::shared_ptr<size_t> columns;

private:
    std::shared_ptr<size_t> alloc_size(const size_t dim);
};

MatrixBase::~MatrixBase(){};

#include "matrix_base.inl"

#endif // __MATRIX_BASE_HPP__