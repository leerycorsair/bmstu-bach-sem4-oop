#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

#include <iterator>
#include <memory>
#include <stddef.h>

#include "exceptions.hpp"

template <typename Type>
class Matrix;

template <typename Type>
class MatrixIterator
    : public std::iterator<std::random_access_iterator_tag, Type>
{
    friend Matrix<Type>;

public:
    MatrixIterator(const MatrixIterator &iter) = default;
    MatrixIterator(
        const std::shared_ptr<typename Matrix<Type>::MatrixRow[]> &data,
        const std::shared_ptr<size_t> &rows,
        const std::shared_ptr<size_t> &columns, const size_t index)
        : data(data), index(index), rows(rows), columns(columns){};

    MatrixIterator<Type> &operator=(const MatrixIterator<Type> &iter);

    bool operator==(const MatrixIterator<Type> &iter) const;
    bool operator!=(const MatrixIterator<Type> &iter) const;
    bool operator<=(const MatrixIterator<Type> &iter) const;
    bool operator<(const MatrixIterator<Type> &iter) const;
    bool operator>(const MatrixIterator<Type> &iter) const;
    bool operator>=(const MatrixIterator<Type> &iter) const;

    operator bool() const;
    bool is_begin() const;
    bool is_end() const;

    MatrixIterator<Type> operator+(const int value) const;
    MatrixIterator<Type> operator-(const int value) const;

    Type &operator*() const;
    Type *operator->() const;

    MatrixIterator<Type> &operator++();
    MatrixIterator<Type> &operator--();

    MatrixIterator<Type> operator++(int);
    MatrixIterator<Type> operator--(int);

    MatrixIterator<Type> &operator+=(const int value);
    MatrixIterator<Type> &operator-=(const int value);

private:
    std::weak_ptr<typename Matrix<Type>::MatrixRow[]> data = nullptr;
    std::weak_ptr<size_t> rows = nullptr;
    std::weak_ptr<size_t> columns = nullptr;
    size_t index = 0;
};

#include "iterator.inl"

#endif // __ITERATOR_HPP__