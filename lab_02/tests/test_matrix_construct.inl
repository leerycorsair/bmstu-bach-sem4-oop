#ifndef __TEST_MATRIX_CONSTRUCT_INL__
#define __TEST_MATRIX_CONSTRUCT_INL__

#include <iostream>
#include <gtest/gtest.h>
#include "matrix.hpp"

TEST(MatrixConstructTests, InitList)
{
    Matrix<int> mtr1 = {{11, -2}, {31, 421}};
    EXPECT_EQ(mtr1, Matrix<int>({{11, -2}, {31, 421}}));
}

TEST(MatrixConstructTests, Copy)
{
    Matrix<int> mtr1 = {{11, -2}, {31, 421}};
    Matrix<int> mtr2 = Matrix<int>(mtr1);

    EXPECT_EQ(mtr2, Matrix<int>({{11, -2}, {31, 421}}));
}

TEST(MatrixConstructTests, NegativeDim)
{
    EXPECT_THROW(Matrix<int> err_m(-100, 5), DimensionsError);
}

TEST(MatrixConstructTests, Filler)
{
    Matrix<double> mtr1(2, 2, 1.0);
    EXPECT_EQ(mtr1, Matrix<double>({{1.0, 1.0}, {1.0, 1.0}}));
}

TEST(MatrixConstructTests, InitListNotOk)
{
    EXPECT_THROW(Matrix<int> mtr1({{1, 2}, {3, 4, 5}}), InitializationError);
}

#endif // __TEST_MATRIX_CONSTRUCT_INL__