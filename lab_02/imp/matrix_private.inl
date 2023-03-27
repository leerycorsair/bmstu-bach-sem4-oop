#ifndef __MATRIX_PRIVATE_INL__
#define __MATRIX_PRIVATE_INL__

#include "matrix.hpp"

template <typename Type>
std::shared_ptr<typename Matrix<Type>::MatrixRow[]> Matrix<Type>::allocate_data(const size_t rows, const size_t columns)
{
    std::shared_ptr<MatrixRow[]> data = nullptr;
    try
    {
        data.reset(new MatrixRow[rows]);
        for (size_t i = 0; i < rows; i++)
            data[i].reset(new Type[columns], columns);
    }
    catch (std::bad_alloc &err)
    {
        time_t curr_time = time(NULL);
        throw MemoryError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return data;
}

template <typename Type>
bool Matrix<Type>::is_initlist_valid(std::initializer_list<std::initializer_list<Type>> init_list, const size_t row_size) const
{
    for (const auto &row : init_list)
        if (row.size() != row_size)
            return false;

    return true;
}

template <typename Type>
void Matrix<Type>::move_row(const size_t from, const size_t to)
{
    auto tmp = this->data[from];

    for (size_t i = from; i > to; --i)
        this->data[i] = this->data[i - 1];

    for (size_t i = from; i < to; ++i)
        this->data[i] = this->data[i + 1];

    this->data[to] = tmp;
}

template <typename Type>
void Matrix<Type>::move_col(const size_t from, const size_t to)
{
    for (size_t j = 0; j < *(this->rows); ++j)
    {
        auto tmp = this->data[j][from];

        for (size_t i = from; i > to; --i)
            this->data[j][i] = this->data[j][i - 1];

        for (size_t i = from; i < to; ++i)
            this->data[j][i] = this->data[j][i + 1];

        this->data[j][to] = tmp;
    }
}

#endif // __MATRIX_PRIVATE_INL__