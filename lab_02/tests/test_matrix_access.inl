#ifndef __TEST_MATRIX_ACCESS_INL__
#define __TEST_MATRIX_ACCESS_INL__

#include <gtest/gtest.h>

#include "matrix.hpp"

TEST(MatrixAccessTest, SqBrOK)
{
    Matrix<int> a = {{54, 41}, {1,2}};

    EXPECT_EQ(a[0][1], 41);
}

TEST(MatrixAccessTest, CirBrOk)
{
   Matrix<int> a = {{54, 41}, {1,2}};

    EXPECT_EQ(a(0, 1), 41);
}

TEST(MatrixAccessTest, AtOK)
{
    Matrix<int> a = {{54, 41}, {1,2}};

    EXPECT_EQ(a.at(0, 1), 41);
}

TEST(MatrixAccessTest, SqBrNotOK)
{
    Matrix<int> a = {{54, 41}, {1,2}};

    EXPECT_THROW(a[0][31], IndexError);
}

TEST(MatrixAccessTest, CirBrNotOk)
{
    Matrix<int> a = {{54, 41}, {1,2}};

    EXPECT_THROW(a(-1, 1), IndexError);
}

TEST(MatrixAccessTest, AtNotOK)
{
    Matrix<int> a = {{54, 41}, {1,2}};

    EXPECT_THROW(a.at(42, 0), IndexError);
}

#endif // __TEST_MATRIX_ACCESS_INL__