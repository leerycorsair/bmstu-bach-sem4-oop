#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <initializer_list>
#include <memory>

#include "matrix_base.hpp"
#include "exceptions.hpp"
#include "iterator.hpp"
#include "const_iterator.hpp"

template <typename Type>
class Matrix : public MatrixBase
{
public:
    class MatrixRow;

    explicit Matrix(const Matrix &mtr);
    Matrix(const int rows = 0, const int columns = 0);
    Matrix(const int rows, const int columns, const Type &filler);
    Matrix(std::initializer_list<std::initializer_list<Type>> init_list);
    Matrix(Matrix &&mtr) noexcept;
    Matrix(Type **mtr, const int rows, const int columns);
    Matrix(const Type **mtr, const int rows, const int columns);

    Matrix<Type> &operator=(std::initializer_list<std::initializer_list<Type>> init_list);
    Matrix<Type> &operator=(const Matrix &mtr);
    Matrix<Type> &operator=(Matrix &&mtr);

    Matrix<Type> operator+(const Matrix &mtr) const;
    Matrix<Type> add_mtr(const Matrix &mtr) const;
    Matrix<Type> &operator+=(const Matrix &mtr);

    Matrix<Type> operator-(const Matrix &mtr) const;
    Matrix<Type> sub_mtr(const Matrix &mtr) const;
    Matrix<Type> &operator-=(const Matrix &mtr);

    Matrix<Type> operator*(const Matrix &mtr) const;
    Matrix<Type> mul_mtr(const Matrix &mtr) const;
    Matrix<Type> &operator*=(const Matrix &mtr);

    Matrix<Type> operator/(const Matrix &mtr) const;
    Matrix<Type> div_mtr(const Matrix &mtr) const;
    Matrix<Type> &operator/=(const Matrix &mtr);

    bool operator==(const Matrix &mtr) const;
    bool operator!=(const Matrix &mtr) const;

    Matrix<Type> operator*(const Type &value) const noexcept;
    Matrix<Type> mul_elems(const Type &value) const noexcept;
    Matrix<Type> &operator*=(const Type &value) noexcept;

    Matrix<Type> operator/(const Type &value) const;
    Matrix<Type> div_elems(const Type &value) const;
    Matrix<Type> &operator/=(const Type &value);

    Matrix<Type> operator-() const;
    Matrix<Type> negative() const;

    MatrixRow operator[](const int row);
    const MatrixRow operator[](const int row) const;

    Type &operator()(const int row, const int column);
    const Type &operator()(const int row, const int column) const;

    Type &at(const int row, const int column);
    const Type &at(const int row, const int column) const;

    void fill(MatrixIterator<Type> start, const MatrixIterator<Type> &end, const Type &filler = {});
    template <typename AnyIterator>
    void fill(MatrixIterator<Type> start, AnyIterator source_start, const AnyIterator &source_end);

    Matrix<Type> &identity_mtr();
    Matrix<Type> &zero_mtr();

    void resize(size_t new_rows, size_t new_columns, const Type &filler = {});
    void resize_rows(const size_t new_size, const Type &filler = {});
    void resize_columns(const size_t new_size, const Type &filler = {});

    void insert_row(const size_t index, const Type &filler = {});
    void insert_row(const size_t index, std::initializer_list<Type> init_list);

    void insert_column(const size_t index, const Type &filler = {});
    void insert_column(const size_t index, std::initializer_list<Type> init_list);

    void delete_row(const size_t index);
    void delete_column(const size_t index);

    Type minor(const size_t row, const size_t columns) const;
    Type determinant() const;
    Matrix<Type> get_transpose();
    Matrix<Type> get_inverse();
    bool is_square() const;

    MatrixIterator<Type> begin();
    MatrixIterator<Type> end();

    ConstMatrixIterator<Type> begin() const;
    ConstMatrixIterator<Type> end() const;
    ConstMatrixIterator<Type> const_begin() const;
    ConstMatrixIterator<Type> const_end() const;

    ~Matrix() override = default;

private:
    std::shared_ptr<MatrixRow[]> data = nullptr;

    std::shared_ptr<MatrixRow[]> allocate_data(const size_t rows, const size_t columns);
    void move_row(const size_t from, const size_t to);
    void move_col(const size_t from, const size_t to);
    bool is_initlist_valid(std::initializer_list<std::initializer_list<Type>> init_list, const size_t row_size) const;

public:
    class MatrixRow
    {
    public:
        MatrixRow(Type *data = nullptr, const size_t size = 0) : data(data), size(size) {}

        Type &operator[](const size_t index);
        const Type &operator[](const size_t index) const;

        void reset(Type *data, const size_t size);
        void reset();

        Type *get_address() { return this->data.get(); }
        const Type *get_address() const { return this->data.get(); }

    private:
        std::shared_ptr<Type[]> data;
        size_t size;
    };
};

#include "matrix_access.inl"
#include "matrix_assign.inl"
#include "matrix_private.inl"
#include "matrix_construct.inl"
#include "matrix_fillers.inl"
#include "matrix_iterators.inl"
#include "matrix_math.inl"
#include "matrix_operations.inl"
#include "matrix_restruct.inl"
#include "matrix_row.inl"

#endif // __MATRIX_HPP__