#ifndef __MATRIX_RESTRUCT_INL__
#define __MATRIX_RESTRUCT_INL__

#include "matrix.hpp"

template <typename Type>
void Matrix<Type>::resize(size_t new_rows, size_t new_columns, const Type &filler)
{
    if (new_rows * new_columns == 0)
        new_rows = 0, new_columns = 0;

    auto tmpData = allocate_data(new_rows, new_columns);

    for (size_t i = 0; i < new_rows; ++i)
        for (size_t j = 0; j < new_columns; ++j)
            tmpData[i][j] = (i < *(this->rows) && j < *(this->columns)) ? this->data[i][j] : filler;

    this->data = tmpData;
    *(this->columns) = new_columns;
    *(this->rows) = new_rows;
}

template <typename Type>
void Matrix<Type>::resize_rows(const size_t new_rows, const Type &filler)
{
    this->resize(new_rows, *(this->columns), filler);
}

template <typename Type>
void Matrix<Type>::resize_columns(const size_t new_columns, const Type &filler)
{
    this->resize(*(this->rows), new_columns, filler);
}

template <typename Type>
void Matrix<Type>::insert_row(const size_t index, const Type &filler)
{
    if (index > *(this->rows))
    {
        time_t curr_time = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    resize_rows(*(this->rows) + 1);

    for (size_t j = 0; j < *(this->columns); ++j)
        this->data[*(this->rows) - 1][j] = filler;

    this->move_row(*(this->rows) - 1, index);
}

template <typename Type>
void Matrix<Type>::insert_row(const size_t index, std::initializer_list<Type> init_list)
{
    if (index > *(this->rows))
    {
        time_t curr_time = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    if (!init_list.size())
    {
        time_t curr_time = time(NULL);
        throw InitializationError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    resize_rows(*(this->rows) + 1);

    size_t k = 0;
    for (const auto &item : init_list)
        this->data[*(this->rows) - 1][k++] = item;

    this->move_row(*(this->rows) - 1, index);
}

template <typename Type>
void Matrix<Type>::insert_column(const size_t index, const Type &filler)
{
    if (index > *(this->columns))
    {
        time_t curr_time = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    resize_columns(*(this->columns) + 1);

    for (size_t i = 0; i < *(this->rows); i++)
        this->data[i][*(this->columns) - 1] = filler;

    this->move_col(*(this->columns) - 1, index);
}

template <typename Type>
void Matrix<Type>::insert_column(const size_t index, std::initializer_list<Type> init_list)
{
    if (index > *(this->columns))
    {
        time_t curr_time = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    if (!init_list.size())
    {
        time_t curr_time = time(NULL);
        throw InitializationError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    resize_columns(*(this->columns) + 1);

    size_t k = 0;
    for (const auto &item : init_list)
        this->data[k++][*(this->columns) - 1] = item;

    this->move_col(*(this->columns) - 1, index);
}

template <typename Type>
void Matrix<Type>::delete_row(const size_t index)
{
    if (index >= *(this->rows))
    {
        time_t curr_time = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    auto tmpData = allocate_data(*(this->rows) - 1, *(this->columns));

    size_t i_dst = 0;
    for (size_t i_src = 0; i_src < *(this->rows); ++i_src)
        if (i_src != index)
        {
            for (size_t j_curr = 0; j_curr < *(this->columns); ++j_curr)
                tmpData[i_dst][j_curr] = this->data[i_src][j_curr];
            ++i_dst;
        }

    this->data = tmpData;
    --*(this->rows);
}

template <typename Type>
void Matrix<Type>::delete_column(const size_t index)
{
    if (index >= *(this->columns))
    {
        time_t curr_time = time(NULL);
        IndexError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    auto tmp = allocate_data(*(this->rows), *(this->columns) - 1);

    size_t j_dst = 0;
    for (size_t j_src = 0; j_src < *(this->columns); ++j_src)
        if (j_src != index)
        {
            for (size_t i_curr = 0; i_curr < *(this->rows); ++i_curr)
                tmp[i_curr][j_dst] = this->data[i_curr][j_src];
            ++j_dst;
        }

    this->data = tmp;
    *(this->columns) = *(this->columns) - 1;
}

template <typename Type>
bool Matrix<Type>::is_square() const
{
    return *(this->rows) == *(this->columns);
}

#endif // __MATRIX_RESTRUCT_INL__
