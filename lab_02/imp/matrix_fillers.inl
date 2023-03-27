#ifndef __MATRIX_FILLERS_INL__
#define __MATRIX_FILLERS_INL__

#include <cstddef>
#include <initializer_list>

#include "matrix.hpp"

template <typename Type>
void Matrix<Type>::fill(MatrixIterator<Type> start, const MatrixIterator<Type> &end, const Type &value)
{
    for (auto iter = start; iter != end; ++iter)
        *iter = value;
}

template <typename Type>
template <typename AnyIterator>
void Matrix<Type>::fill(MatrixIterator<Type> start, AnyIterator source_start, const AnyIterator &source_end)
{
    auto source_iter = source_start;
    auto iter = start;

    while (!iter.is_end() && source_iter != source_end)
        *iter++ = *source_iter++;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::zero_mtr()
{
    this->fill(this->begin(), this->end());
    return *this;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::identity_mtr()
{
    for (size_t i = 0; i < *(this->rows); ++i)
        for (size_t j = 0; j < *(this->columns); ++j)
            this->data[i][j] = (i == j) ? 1 : 0;

    return *this;
}

#endif // __MATRIX_FILLERS_INL__
