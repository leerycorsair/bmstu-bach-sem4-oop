#ifndef __CONST_ITERATOR_INL__
#define __CONST_ITERATOR_INL__

#include "const_iterator.hpp"
#include <ctime>

template <typename Type>
ConstMatrixIterator<Type> &ConstMatrixIterator<Type>::operator=(const ConstMatrixIterator<Type> &iter)
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
bool ConstMatrixIterator<Type>::operator==(const ConstMatrixIterator<Type> &iter) const
{
    if (!this || !iter)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->index == iter.index;
}

template <typename Type>
bool ConstMatrixIterator<Type>::operator!=(const ConstMatrixIterator<Type> &iter) const
{
    if (!this || !iter)
#
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return !(*this == iter);
}

template <typename Type>
bool ConstMatrixIterator<Type>::operator<(const ConstMatrixIterator<Type> &iter) const
{
    if (!this || !iter)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->index < iter.index;
}

template <typename Type>
bool ConstMatrixIterator<Type>::operator<=(const ConstMatrixIterator<Type> &iter) const
{
    if (!this || !iter)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->index <= iter.index;
}

template <typename Type>
bool ConstMatrixIterator<Type>::operator>(const ConstMatrixIterator<Type> &iter) const
{
    if (!this || !iter)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->index > iter.index;
}

template <typename Type>
bool ConstMatrixIterator<Type>::operator>=(const ConstMatrixIterator<Type> &iter) const
{
    if (!this || !iter)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->index >= iter.index;
}

template <typename Type>
ConstMatrixIterator<Type>::operator bool() const
{
    return !(this->data.expired() || this->rows.expired() || this->columns.expired());
}

template <typename Type>
bool ConstMatrixIterator<Type>::is_begin() const
{
    if (!this)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->index == 0;
}

template <typename Type>
bool ConstMatrixIterator<Type>::is_end() const
{
    if (!this)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    return this->index == *(this->rows.lock()) * *(this->columns.lock());
}

template <typename Type>
ConstMatrixIterator<Type> ConstMatrixIterator<Type>::operator+(const int value) const
{
    if (!this)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    ConstMatrixIterator<Type> iter(*this);

    if (value < 0 && iter.index < static_cast<size_t>(-value))
        iter.index = 0;
    else
        iter.index += value;

    if (iter.index > *(this->rows.lock()) * *(this->columns.lock()))
        iter.index = *(this->rows.lock()) * *(this->columns.lock());

    return iter;
}

template <typename Type>
ConstMatrixIterator<Type> ConstMatrixIterator<Type>::operator-(const int value) const
{
    return operator+(-value);
}

template <typename Type>
const Type &ConstMatrixIterator<Type>::operator*() const
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
const Type *ConstMatrixIterator<Type>::operator->() const
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
ConstMatrixIterator<Type> &ConstMatrixIterator<Type>::operator++()
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
ConstMatrixIterator<Type> &ConstMatrixIterator<Type>::operator--()
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
ConstMatrixIterator<Type> ConstMatrixIterator<Type>::operator++(int)
{
    if (!this)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    ConstMatrixIterator<Type> iter(*this);
    ++(*this);
    return iter;
}

template <typename Type>
ConstMatrixIterator<Type> ConstMatrixIterator<Type>::operator--(int)
{
    if (!this)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    ConstMatrixIterator<Type> iter(*this);
    --(*this);
    return iter;
}

template <typename Type>
ConstMatrixIterator<Type> &ConstMatrixIterator<Type>::operator+=(const int value)
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
ConstMatrixIterator<Type> &ConstMatrixIterator<Type>::operator-=(const int value)
{
    if (!this)
    {
        time_t curr_time = time(NULL);
        throw PointerError(__FILE__, typeid(*this).name(), __FUNCTION__, __LINE__, ctime(&curr_time), "INFO");
    }

    *this = *this - value;
    return *this;
}

#endif //__CONST_ITERATOR_INL__