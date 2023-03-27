#ifndef __MATRIX_ASSIGN_INL__
#define __MATRIX_ASSIGN_INL__

#include "matrix.hpp"

template <typename Type>
Matrix<Type> &Matrix<Type>::operator=(const Matrix &mtr)
{
    if (this == &mtr)
        return *this;

    this->data = allocate_data(*(mtr.rows), *(mtr.columns));
    *(this->rows) = *(mtr.rows), *(this->columns) = *(mtr.columns);

    for (size_t i = 0; i < *(this->rows); ++i)
        for (size_t j = 0; j < *(this->columns); ++j)
            this->data[i][j] = mtr[i][j];

    return *this;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator=(Matrix &&mtr)
{
    if (this == &mtr)
        return *this;

    this->data = mtr.data;
    *(this->rows) = *(mtr.rows), *(this->columns) = *(mtr.columns);

    return *this;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator=(std::initializer_list<std::initializer_list<Type>> init_list)
{
    size_t rows = init_list.size();
    size_t columns = init_list.size() ? init_list.begin()->size() : 0;

    if (!this->is_initlist_valid(init_list, columns))
    {
        time_t curr_time = time(NULL);
        throw InitializationError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    this->resize(rows, columns);
    size_t i = 0;
    for (const auto &row : init_list)
        for (const auto &item : row)
        {
            this->data[i / columns][i % columns] = item;
            ++i;
        }

    return *this;
}

#endif // __MATRIX_ASSIGN_INL__