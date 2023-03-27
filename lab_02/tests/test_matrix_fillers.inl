#ifndef __TEST_MATRIX_FILLERS_INL__
#define __TEST_MATRIX_FILLERS_INL__

#include <gtest/gtest.h>

#include "matrix.hpp"

TEST(MatrixFillersTests, FullFill)
{
    Matrix<int> mtr1(2, 3);
    Matrix<int> mtr2 = {{1, 1, 1}, {1, 1, 1}};

    mtr1.fill(mtr1.begin(), mtr1.end(), 1);

    EXPECT_EQ(mtr1, mtr2);
}

TEST(MatrixFillersTests, FullFillDefaultFiller)
{
    Matrix<int> mtr1(2, 3);
    Matrix<int> mtr2 = {{0, 0, 0}, {0, 0, 0}};

    mtr1.fill(mtr1.begin(), mtr1.end());

    EXPECT_EQ(mtr1, mtr2);
}

TEST(MatrixFillersTests, FirstRowFill)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}};
    Matrix<int> mtr2 = {{0, 0}, {3, 4}};

    auto it_start = mtr1.begin();

    auto it_end = mtr1.begin() + 2;

    mtr1.fill(it_start, it_end, 0);

    EXPECT_EQ(mtr1, mtr2);
}

TEST(MatrixFillersTests, FillFromSource)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}};
    Matrix<int> mtr2 = {{9, 8}, {7, 6}};

    mtr2 = {{1, 8}, {7, 4}};

    auto it_start = mtr1.begin() + 1;

    auto it_src_start = mtr2.begin() + 1;
    auto it_src_end = mtr2.end() - 1;

    mtr1.fill(it_start, it_src_start, it_src_end);

    EXPECT_EQ(mtr1, mtr2);
}

TEST(MatrixFillersTests, FillFromSourceConst)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}};
    Matrix<int> mtr2 = {{9, 8}, {7, 6}};

    mtr2 = {{1, 8}, {7, 4}};

    auto it_start = mtr1.begin() + 1;

    auto it_src_start = mtr2.const_begin() + 1;
    auto it_src_end = mtr2.const_end() - 1;

    mtr1.fill(it_start, it_src_start, it_src_end);

    EXPECT_EQ(mtr1, mtr2);
}

TEST(MatrixFillersTests, FillFromSourceAnyConst)
{

    const std::array<int, 4> filler = {9, 8, 7, 6};
    Matrix<int> mtr1 = {{1, 2}, {3, 4}};

    const Matrix<int> mtr2 = {{1, 8}, {7, 4}};

    auto it_start = mtr1.begin() + 1;

    auto it_src_start = mtr2.const_begin() + 1;
    auto it_src_end = mtr2.const_end() - 1;

    mtr1.fill(it_start, it_src_start, it_src_end);

    EXPECT_EQ(mtr1, mtr2);
}

TEST(MatrixFillersTests, ZerosFill)
{
    Matrix<int> mtr1(2, 2);
    Matrix<int> mtr2 = {{0, 0}, {0, 0}};

    EXPECT_EQ(mtr1.zero_mtr(), mtr2);
}

TEST(MatrixFillersTests, IdentityFillInt)
{
    Matrix<int> mtr1(2, 2);
    Matrix<int> mtr2 = {{1, 0}, {0, 1}};

    EXPECT_EQ(mtr1.identity_mtr(), mtr2);
}

TEST(MatrixFillersTests, IdentityFillDouble)
{
    Matrix<double> mtr1(2, 2);
    Matrix<double> mtr2 = {{1.0, 0.0}, {0.0, 1.0}};

    EXPECT_EQ(mtr1.identity_mtr(), mtr2);
}

#endif // __TEST_MATRIX_FILLERS_INL__