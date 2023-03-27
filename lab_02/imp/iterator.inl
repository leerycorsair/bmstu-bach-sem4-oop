#ifndef __ITERATOR_INL__
#define __ITERATOR_INL__

#include "iterator.hpp"

template <typename Type>
MatrixIterator<Type> &MatrixIterator<Type>::operator=(const MatrixIterator<Type> &iter)
{
    if (!iter)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    this->data = iter.data;
    this->index = iter.index;
    this->rows = iter.rows;
    this->columns = iter.columns;
    return *this;
}

template <typename Type>
bool MatrixIterator<Type>::operator==(const MatrixIterator<Type> &iter) const
{
    if (!this || !iter)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->index == iter.index;
}

template <typename Type>
bool MatrixIterator<Type>::operator!=(const MatrixIterator<Type> &iter) const
{
    if (!this || !iter)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return !(*this == iter);
}

template <typename Type>
bool MatrixIterator<Type>::operator<(const MatrixIterator<Type> &iter) const
{
    if (!this || !iter)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->index < iter.index;
}

template <typename Type>
bool MatrixIterator<Type>::operator<=(const MatrixIterator<Type> &iter) const
{
    if (!this || !iter)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->index <= iter.index;
}

template <typename Type>
bool MatrixIterator<Type>::operator>(const MatrixIterator<Type> &iter) const
{
    if (!this || !iter)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->index > iter.index;
}

template <typename Type>
bool MatrixIterator<Type>::operator>=(const MatrixIterator<Type> &iter) const
{
    if (!this || !iter)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->index >= iter.index;
}

template <typename Type>
MatrixIterator<Type>::operator bool() const
{
    return !(this->data.expired() || this->rows.expired() || this->columns.expired());
}

template <typename Type>
bool MatrixIterator<Type>::is_begin() const
{
    if (!this)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->index == 0;
}

template <typename Type>
bool MatrixIterator<Type>::is_end() const
{
    if (!this)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->index == *(this->rows.lock()) * *(this->columns.lock());
}

template <typename Type>
MatrixIterator<Type> MatrixIterator<Type>::operator+(const int value) const
{
    if (!this)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    MatrixIterator<Type> iter(*this);

    if (value < 0 && iter.index < static_cast<size_t>(-value))
        iter.index = 0;
    else
        iter.index += value;

    if (iter.index > *(this->rows.lock()) * *(this->columns.lock()))
        iter.index = *(this->rows.lock()) * *(this->columns.lock());

    return iter;
}

template <typename Type>
MatrixIterator<Type> MatrixIterator<Type>::operator-(const int value) const
{
    return operator+(-value);
}

template <typename Type>
Type &MatrixIterator<Type>::operator*() const
{
    if (!this)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    if (this->index >= *(this->rows.lock()) * *(this->columns.lock()))
    {
        time_t curr_time = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    auto dataPtr = this->data.lock();
    return dataPtr[this->index / *(this->columns.lock())][this->index % *(this->columns.lock())];
}

template <typename Type>
Type *MatrixIterator<Type>::operator->() const
{

    if (!this)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }
    if (this->index >= *(this->rows.lock()) * *(this->columns.lock()))
    {
        time_t curr_time = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    auto dataPtr = this->data.lock();
    return this->dataPtr[this->index / *(this->columns.lock())].getAddr() + (this->index % *(this->columns.lock()));
}

template <typename Type>
MatrixIterator<Type> &MatrixIterator<Type>::operator++()
{
    if (!this)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }
    if (this->index < *(this->columns.lock()) * *(this->rows.lock()))
        ++this->index;
    return *this;
}

template <typename Type>
MatrixIterator<Type> &MatrixIterator<Type>::operator--()
{
    if (!this)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }
    if (this->index > 0)
        --this->index;
    return *this;
}

template <typename Type>
MatrixIterator<Type> MatrixIterator<Type>::operator++(int)
{
    if (!this)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }
    MatrixIterator<Type> iter(*this);
    ++(*this);
    return iter;
}

template <typename Type>
MatrixIterator<Type> MatrixIterator<Type>::operator--(int)
{
    if (!this)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }
    MatrixIterator<Type> iter(*this);
    --(*this);
    return iter;
}

template <typename Type>
MatrixIterator<Type> &MatrixIterator<Type>::operator+=(const int value)
{
    if (!this)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }
    *this = *this + value;
    return *this;
}

template <typename Type>
MatrixIterator<Type> &MatrixIterator<Type>::operator-=(const int value)
{
    if (!this)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    *this = *this - value;
    return *this;
}

#endif //__ITERATOR_INL__