#ifndef __MATRIX_MATH_INL__
#define __MATRIX_MATH_INL__

#include "matrix.hpp"

template <typename Type>
static Type _determinant(const Matrix<Type> &mtr)
{
    if (!mtr)
        return 1;

    size_t rows = mtr.get_rows(), columns = mtr.get_columns();

    if (rows == 2)
        return mtr[0][0] * mtr[1][1] - mtr[1][0] * mtr[0][1];
    if (rows == 1)
        return mtr[0][0];

    Type result = {};
    for (size_t j = 0; j < columns; ++j)
    {
        Type minor = mtr.minor(0, j);
        result += j & 1 ? -mtr[0][j] * minor : mtr[0][j] * minor;
    }

    return result;
}

template <typename Type>
Type Matrix<Type>::minor(const size_t row, const size_t column) const
{
    if (!this->is_square())
    {
        time_t curr_time = time(NULL);
        throw MatrixSquareError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    Matrix<Type> cut_matrix(*(this->rows) - 1, *(this->columns) - 1);

    size_t row_index, column_index;
    for (size_t i = 0; i < *(this->rows) - 1; ++i)
        for (size_t j = 0; j < *(this->columns) - 1; ++j)
        {
            row_index = i >= row ? i + 1 : i;
            column_index = j >= column ? j + 1 : j;
            cut_matrix[i][j] = this->data[row_index][column_index];
        }

    return _determinant(cut_matrix);
}

template <typename Type>
Matrix<Type> Matrix<Type>::get_transpose()
{
    if (!*this || (*(this->rows) == *(this->columns) == 1))
        return Matrix<Type>(*this);

    Matrix<Type> result(*(this->columns), *(this->rows));

    for (size_t i = 0; i < *(this->rows); ++i)
        for (size_t j = 0; j < *(this->columns); ++j)
            result[j][i] = this->data[i][j];

    return result;
}

template <typename Type>
Type Matrix<Type>::determinant() const
{
    if (!this->is_square())
    {
        time_t curr_time = time(NULL);
        throw MatrixSquareError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return _determinant(*this);
}

template <typename Type>
Matrix<Type> Matrix<Type>::get_inverse()
{
    if (!*this)
        return Matrix<Type>(*this);

    if (!this->is_square())
    {
        time_t curr_time = time(NULL);
        throw MatrixSquareError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    Type det = this->determinant();
    if (!det)
    {
        time_t curr_time = time(NULL);
        throw MatrixSingularError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    Matrix<Type> result(*(this->rows), *(this->columns));
    Type value = {};

    for (size_t i = 0; i < *(this->rows); ++i)
        for (size_t j = 0; j < *(this->columns); ++j)
        {
            value = this->minor(i, j) / det;
            result[j][i] = (i + j) & 1 ? -value : value;
        }

    return result;
}

#endif // __MATRIX_MATH_INL__