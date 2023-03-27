#ifndef __MATRIX_ITERATORS_INL__
#define __MATRIX_ITERATORS_INL__

#include "matrix.hpp"

template <typename Type>
MatrixIterator<Type> Matrix<Type>::begin()
{
    return MatrixIterator<Type>(this->data, this->rows, this->columns, 0);
}

template <typename Type>
MatrixIterator<Type> Matrix<Type>::end()
{
    return MatrixIterator<Type>(this->data, this->rows, this->columns, *(this->columns) * *(this->rows));
}

template <typename Type>
ConstMatrixIterator<Type> Matrix<Type>::begin() const
{
    return ConstMatrixIterator<Type>(this->data, this->rows, this->columns, 0);
}

template <typename Type>
ConstMatrixIterator<Type> Matrix<Type>::end() const
{
    return ConstMatrixIterator<Type>(this->data, this->rows, this->columns, *(this->columns) * *(this->rows));
}

template <typename Type>
ConstMatrixIterator<Type> Matrix<Type>::const_begin() const
{
    return ConstMatrixIterator<Type>(this->data, this->rows, this->columns, 0);
}

template <typename Type>
ConstMatrixIterator<Type> Matrix<Type>::const_end() const
{
    return ConstMatrixIterator<Type>(this->data, this->rows, this->columns, *(this->columns) * *(this->rows));
}

#endif // __MATRIX_ITERATORS_INL__