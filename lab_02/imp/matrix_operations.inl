#ifndef __MATRIX_OPERATIONS_INL__
#define __MATRIX_OPERATIONS_INL__

#include "matrix.hpp"

template <typename Type>
Matrix<Type> Matrix<Type>::operator+(const Matrix<Type> &mtr) const
{
    if (!(*(this->rows) == *(mtr.rows) && *(this->columns) == *(mtr.columns)))
    {
        time_t curr_time = time(NULL);
        throw MatrixUnmatchError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    Matrix<Type> result_mtr(*(this->rows), *(this->columns));

    for (size_t i = 0; i < *(this->rows); ++i)
        for (size_t j = 0; j < *(this->columns); ++j)
            result_mtr[i][j] = this->data[i][j] + mtr[i][j];

    return result_mtr;
}

template <typename Type>
Matrix<Type> Matrix<Type>::operator-(const Matrix<Type> &mtr) const
{
    if (!(*(this->rows) == *(mtr.rows) && *(this->columns) == *(mtr.columns)))
    {
        time_t curr_time = time(NULL);
        throw MatrixUnmatchError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    Matrix<Type> result_mtr(*(this->rows), *(this->columns));

    for (size_t i = 0; i < *(this->rows); ++i)
        for (size_t j = 0; j < *(this->columns); ++j)
            result_mtr[i][j] = this->data[i][j] - mtr[i][j];

    return result_mtr;
}

template <typename Type>
Matrix<Type> Matrix<Type>::operator*(const Matrix<Type> &mtr) const
{
    if (*(this->columns) != *(mtr.rows))
    {
        time_t curr_time = time(NULL);
        throw MatrixUnmatchError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    Matrix<Type> result_mtr(*(this->rows), *(mtr.columns), 0);

    for (size_t i = 0; i < *(this->rows); ++i)
        for (size_t j = 0; j < *(mtr.columns); ++j)
            for (size_t k = 0; k < *(this->columns); ++k)
                result_mtr[i][j] += this->data[i][k] * mtr[k][j];

    return result_mtr;
}

template <typename Type>
Matrix<Type> Matrix<Type>::operator*(const Type &value) const noexcept
{
    Matrix<Type> result_mtr(*(this->rows), *(this->columns), 0);

    for (size_t i = 0; i < *(this->rows); ++i)
        for (size_t j = 0; j < *(this->columns); ++j)
            result_mtr[i][j] = this->data[i][j] * value;

    return result_mtr;
}

template <typename Type>
Matrix<Type> Matrix<Type>::operator/(const Matrix &mtr) const
{
    Matrix<Type> result_mtr(mtr);
    return *this * result_mtr.get_inverse();
}

template <typename Type>
Matrix<Type> Matrix<Type>::operator/(const Type &value) const
{
    if (!value)
    {
        time_t curr_time = time(NULL);
        throw ZeroDivisionError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    Matrix<Type> result_mtr(*(this->rows), *(this->columns));

    for (size_t i = 0; i < *(this->rows); ++i)
        for (size_t j = 0; j < *(this->columns); ++j)
            result_mtr[i][j] = this->data[i][j] / value;

    return result_mtr;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator+=(const Matrix &mtr)
{
    if (!(*(this->rows) == *(mtr.rows) && *(this->columns) == *(mtr.columns)))
    {
        time_t curr_time = time(NULL);
        throw MatrixUnmatchError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    for (size_t i = 0; i < *(this->rows); ++i)
        for (size_t j = 0; j < *(this->columns); ++j)
            this->data[i][j] += mtr[i][j];

    return *this;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator-=(const Matrix &mtr)
{
    if (!(*(this->rows) == *(mtr.rows) && *(this->columns) == *(mtr.columns)))
    {
        time_t curr_time = time(NULL);
        throw MatrixUnmatchError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    for (size_t i = 0; i < *(this->rows); ++i)
        for (size_t j = 0; j < *(this->columns); ++j)
            this->data[i][j] -= mtr[i][j];

    return *this;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator*=(const Matrix &mtr)
{
    *this = *this * mtr;
    return *this;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator*=(const Type &value) noexcept
{
    *this = *this * value;
    return *this;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator/=(const Type &value)
{
    if (!value)
    {
        time_t curr_time = time(NULL);
        throw ZeroDivisionError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    for (size_t i = 0; i < *(this->rows); ++i)
        for (size_t j = 0; j < *(this->columns); ++j)
            this->data[i][j] /= value;

    return *this;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator/=(const Matrix &mtr)
{
    *this = *this / mtr;
    return *this;
}

template <typename Type>
Matrix<Type> Matrix<Type>::operator-() const
{
    Matrix<Type> result_mtr(*(this->rows), *(this->columns));

    for (size_t i = 0; i < *(this->rows); ++i)
        for (size_t j = 0; j < *(this->columns); ++j)
            result_mtr[i][j] = -this->data[i][j];

    return result_mtr;
}

template <typename Type>
Matrix<Type> Matrix<Type>::add_mtr(const Matrix &mtr) const
{
    return *this + mtr;
}

template <typename Type>
Matrix<Type> Matrix<Type>::sub_mtr(const Matrix &mtr) const
{
    return *this - mtr;
}

template <typename Type>
Matrix<Type> Matrix<Type>::mul_mtr(const Matrix &mtr) const
{
    return *this * mtr;
}

template <typename Type>
Matrix<Type> Matrix<Type>::mul_elems(const Type &value) const noexcept
{
    return *this * value;
}

template <typename Type>
Matrix<Type> Matrix<Type>::div_mtr(const Matrix &mtr) const
{
    return *this / mtr;
}

template <typename Type>
Matrix<Type> Matrix<Type>::div_elems(const Type &value) const
{
    return *this / value;
}

template <typename Type>
Matrix<Type> Matrix<Type>::negative() const
{
    return -*this;
}

template <typename Type>
Matrix<Type> operator+(const Type &value, const Matrix<Type> &matrix)
{
    return matrix + value;
}

template <typename Type>
Matrix<Type> operator-(const Type &value, const Matrix<Type> &matrix)
{
    return -matrix + value;
}

template <typename Type>
Matrix<Type> operator*(const Type &value, const Matrix<Type> &matrix)
{
    return matrix * value;
}

template <typename Type>
Matrix<Type> operator/(const Type &value, const Matrix<Type> &matrix)
{
    Matrix<Type> result_mtr(matrix);
    return result_mtr.get_inverse() * value;
}

template <typename Type>
std::ostream &operator<<(std::ostream &out, const Matrix<Type> &matrix)
{
    for (size_t i = 0; i < matrix.get_rows(); ++i)
    {
        for (size_t j = 0; j < matrix.get_columns(); ++j)
            out << matrix[i][j] << '\t';

        out << '\n';
    }

    return out;
}

#endif // __MATRIX_OPERATIONS_INL__