#ifndef __MATRIX_ROW_INL__
#define __MATRIX_ROW_INL__

#include "matrix.hpp"

template <typename Type>
const Type &Matrix<Type>::MatrixRow::operator[](const size_t index) const
{
    if (index >= this->size)
    {
        time_t curr_time = time(NULL);
        throw(IndexError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO"));
    }

    return this->data[index];
}

template <typename Type>
Type &Matrix<Type>::MatrixRow::operator[](const size_t index)
{
    if (index >= this->size)
    {
        time_t curr_time = time(NULL);
        throw(IndexError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO"));
    }

    return this->data[index];
}

template <typename Type>
void Matrix<Type>::MatrixRow::reset()
{
    this->size = 0;
    this->data.reset();
}

template <typename Type>
void Matrix<Type>::MatrixRow::reset(Type *data, const size_t size)
{
    this->size = size;
    this->data.reset(data);
}

#endif // __MATRIX_ROW_INL__
