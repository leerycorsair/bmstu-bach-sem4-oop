#ifndef __MATRIX_CONSTRUCT_INL__
#define __MATRIX_CONSTRUCT_INL__

#include <cstddef>
#include <initializer_list>
#include <ctime>

#include "matrix.hpp"

template <typename Type>
Matrix<Type>::Matrix(const int rows, const int columns) : MatrixBase(columns ? rows : 0, rows ? columns : 0)
{
    if (rows < 0 || columns < 0)
    {
        time_t curr_time = time(NULL);
        throw DimensionsError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    this->data = allocate_data(*(this->rows), *(this->columns));
}

template <typename Type>
Matrix<Type>::Matrix(const int rows, const int columns, const Type &filler) : Matrix(rows, columns)
{
    this->fill(this->begin(), this->end(), filler);
}

template <typename Type>
Matrix<Type>::Matrix(std::initializer_list<std::initializer_list<Type>> init_list) : Matrix(init_list.size(), init_list.size() ? init_list.begin()->size() : 0)
{
    if (!this->is_initlist_valid(init_list, *(this->columns)))
    {
        time_t curr_time = time(NULL);
        throw InitializationError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    auto it = this->begin();

    for (const auto &row : init_list)
        for (const auto &elem : row)
            *it++ = elem;
}

template <typename Type>
Matrix<Type>::Matrix(Type **matrix, const int rows, const int columns) : MatrixBase(rows, columns)
{
    if (!matrix)
    {
        time_t curr_time = time(NULL);
        throw IncorrectCMatrixError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    this->data = allocate_data(rows, columns);

    for (size_t i = 0; i < rows; ++i)
    {
        if (!matrix)
        {
            time_t curr_time = time(NULL);
            throw IncorrectCMatrixError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
        }

        for (size_t j = 0; j < columns; ++j)
            this->data[i][j] = matrix[i][j];
    }
}

template <typename Type>
Matrix<Type>::Matrix(const Type **matrix, const int rows, const int columns) : MatrixBase(rows, columns)
{
    if (!matrix)
    {
        time_t curr_time = time(NULL);
        throw IncorrectCMatrixError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    this->data = allocate_data(rows, columns);

    for (size_t i = 0; i < rows; ++i)
    {
        if (!matrix)
        {
            time_t curr_time = time(NULL);
            throw IncorrectCMatrixError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
        }

        for (size_t j = 0; j < columns; ++j)
            this->data[i][j] = matrix[i][j];
    }
}

template <typename Type>
Matrix<Type>::Matrix(const Matrix &mtr) : Matrix(*(mtr.rows), *(mtr.columns))
{
    this->fill(this->begin(), mtr.begin(), mtr.end());
}

template <typename Type>
Matrix<Type>::Matrix(Matrix &&mtr) noexcept : MatrixBase(*(mtr.rows), *(mtr.columns))
{
    this->data = mtr.data;
}

#endif // __MATRIX_CONSTRUCT_INL__
