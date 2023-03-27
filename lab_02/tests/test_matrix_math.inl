#ifndef __TESTS_MATRIX_MATH_INL__
#define __TESTS_MATRIX_MATH_INL__

#include <gtest/gtest.h>

#include "matrix.hpp"

TEST(MatrixMathTests, DeterminantLittle)
{
    Matrix<double> mtr1 = {{1, 2}, {3, 4}};

    EXPECT_EQ(mtr1.determinant(), -2.0);
}

TEST(MatrixMathTests, DeterminantBig)
{
    Matrix<double> mtr1(4, 4);

    int k = 1;
    for (auto &item : mtr1)
        item = k++;

    EXPECT_EQ(mtr1.determinant(), 0.0);
}

TEST(MatrixMathTests, DeterminantNonSquare)
{
    Matrix<double> mtr1 = {{1, 2, 3}, {4, 5, 6}};

    EXPECT_THROW(mtr1.determinant(), MatrixSquareError);
}

TEST(MatrixMathTests, Transpose)
{
    Matrix<double> mtr1 = {{1, 2, 3}, {4, 5, 6}};
    Matrix<double> mtr2 = {{1, 4}, {2, 5}, {3, 6}};

    EXPECT_EQ(mtr1.get_transpose(), mtr2);
}

TEST(MatrixMathTests, InverseSingular)
{
    Matrix<double> mtr1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    EXPECT_THROW(mtr1.get_inverse(), MatrixSingularError);
}

TEST(MatrixMathTests, Minor)
{
    Matrix<double> mtr1 = {{1, 2}, {3, 4}};
    EXPECT_EQ(mtr1.minor(0, 0), 4);
}

TEST(MatrixMathTests, MinorNonSquare)
{
    Matrix<double> mtr1 = {{1, 2, 3}, {4, 5, 6}};
    EXPECT_THROW(mtr1.minor(0, 0), MatrixSquareError);
}

#endif // __TEST_MATRIX_MATH_INL__