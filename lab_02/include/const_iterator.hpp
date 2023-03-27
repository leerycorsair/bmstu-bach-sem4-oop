#ifndef __CONST_ITERATOR_HPP__
#define __CONST_ITERATOR_HPP__

#include <iterator>
#include <memory>
#include <stddef.h>

#include "exceptions.hpp"

template <typename Type>
class Matrix;

template <typename Type>
class ConstMatrixIterator
    : public std::iterator<std::random_access_iterator_tag, Type>
{
    friend Matrix<Type>;

public:
    ConstMatrixIterator(const ConstMatrixIterator &iter) = default;
    ConstMatrixIterator(
        const std::shared_ptr<typename Matrix<Type>::MatrixRow[]> &data,
        const std::shared_ptr<size_t> &rows,
        const std::shared_ptr<size_t> &columns, const size_t index)
        : data(data), index(index), rows(rows), columns(columns){};

    ConstMatrixIterator<Type> &operator=(const ConstMatrixIterator<Type> &iter);

    bool operator==(ConstMatrixIterator<Type> const &iter) const;
    bool operator!=(ConstMatrixIterator<Type> const &iter) const;
    bool operator<=(const ConstMatrixIterator<Type> &iter) const;
    bool operator<(const ConstMatrixIterator<Type> &iter) const;
    bool operator>(const ConstMatrixIterator<Type> &iter) const;
    bool operator>=(const ConstMatrixIterator<Type> &iter) const;

    operator bool() const;
    bool is_begin() const;
    bool is_end() const;

    ConstMatrixIterator<Type> operator+(const int value) const;
    ConstMatrixIterator<Type> operator-(const int value) const;

    const Type &operator*() const;
    const Type *operator->() const;

    ConstMatrixIterator<Type> &operator++();
    ConstMatrixIterator<Type> &operator--();

    ConstMatrixIterator<Type> operator++(int value);
    ConstMatrixIterator<Type> operator--(int value);

    ConstMatrixIterator<Type> &operator+=(const int value);
    ConstMatrixIterator<Type> &operator-=(const int value);

private:
    std::weak_ptr<typename Matrix<Type>::MatrixRow[]> data = nullptr;
    std::weak_ptr<size_t> rows = nullptr;
    std::weak_ptr<size_t> columns = nullptr;
    size_t index = 0;
};

#include "const_iterator.inl"

#endif // __CONST_ITERATOR_HPP__