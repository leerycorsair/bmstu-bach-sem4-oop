#ifndef __TEST__MATRIX_ASSIGN_INL__
#define __TEST__MATRIX_ASSIGN_INL__

#include <iostream>
#include <gtest/gtest.h>
#include "matrix.hpp"

TEST(MatrixAssignTest, AssignMatrix)
{
    Matrix<int> mtr1 = {{12, 31}, {12, 12}, {21,21}};
    Matrix<int> mtr2;

    mtr2 = mtr1;

    EXPECT_EQ(mtr1, mtr2);
}

TEST(MatrixAssignTest, AssignConstMatrix)
{
    const Matrix<int> mtr1 = {{12, 31}, {12, 12}, {21,21}};
    Matrix<int> mtr2;

    mtr2 = mtr1;

    EXPECT_EQ(mtr1, mtr2);
}

TEST(MatrixAssignTest, AssignInitListOK)
{
    Matrix<int> mtr1;
    mtr1 = {{12, 31}, {12, 12}, {21,21}};

    EXPECT_EQ(mtr1, Matrix<int>({{12, 31}, {12, 12}, {21,21}}));
}

TEST(MatrixAssignTest, AssignInitListNotOk)
{
    Matrix<int> mtr1;
    EXPECT_THROW((mtr1 = {{12}, {12, 12}, {21}}), InitializationError);
}

#endif // __TEST__MATRIX_ASSIGN_INL__