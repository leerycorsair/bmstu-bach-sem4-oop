#ifndef __MATRIX_ACCESS_INL__
#define __MATRIX_ACCESS_INL__

#include "matrix.hpp"

template <typename Type>
bool Matrix<Type>::operator==(const Matrix &mtr) const
{
    if (*(this->rows) != *(mtr.rows) || *(this->columns) != *(mtr.columns))
        return false;

    bool equ = true;
    for (size_t i = 0; i < *(this->rows) && equ; ++i)
        for (size_t j = 0; j < *(this->columns) && equ; ++j)
            equ = (this->data[i][j] == mtr[i][j]);

    return equ;
}

template <typename Type>
bool Matrix<Type>::operator!=(const Matrix &mtr) const
{
    return !(*this == mtr);
}

template <typename Type>
typename Matrix<Type>::MatrixRow Matrix<Type>::operator[](const int row)
{
    if (row < 0 || row >= *(this->rows))
    {
        time_t curr_time = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->data[row];
}

template <typename Type>
const typename Matrix<Type>::MatrixRow Matrix<Type>::operator[](const int row) const
{
    if (row < 0 || row >= *(this->rows))
    {
        time_t curr_time = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->data[row];
}

template <typename Type>
Type &Matrix<Type>::operator()(const int row, const int column)
{
    if (row < 0 || column < 0 || row >= *(this->rows) || column >= *(this->columns))
    {
        time_t curr_time = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->data[row][column];
}

template <typename Type>
Type &Matrix<Type>::at(const int row, const int column)
{
    if (row < 0 || column < 0 || row >= *(this->rows) || column >= *(this->columns))
    {
        time_t curr_time = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->data[row][column];
}

template <typename Type>
const Type &Matrix<Type>::operator()(const int row, const int column) const
{
    if (row < 0 || column < 0 || row >= *(this->rows) || column >= *(this->columns))
    {
        time_t curr_time = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->data[row][column];
}

template <typename Type>
const Type &Matrix<Type>::at(const int row, const int column) const
{
    if (row < 0 || column < 0 || row >= *(this->rows) || column >= *(this->columns))
    {
        time_t curr_time = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->data[row][column];
}

#endif // __MATRIX_ACCESS_INL__
