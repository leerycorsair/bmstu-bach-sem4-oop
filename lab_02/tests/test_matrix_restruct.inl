#ifndef __TEST_MATRIX_RESTRUCT_INL__
#define __TEST_MATRIX_RESTRUCT_INL__

#include <gtest/gtest.h>

#include "matrix.hpp"

TEST(RestructTests, ResizePlus)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}};
    Matrix<int> mtr2 = {{1, 2, 0, 0}, {3, 4, 0, 0}, {0, 0, 0, 0}};

    mtr1.resize(3, 4, 0);

    EXPECT_EQ(mtr1, mtr2);
}

TEST(RestructTests, ResizeMinus)
{
    Matrix<int> mtr1 = {{1, 2, 3}, {3, 4, 5}};
    Matrix<int> mtr2 = {{1, 2}, {3, 4}};

    mtr1.resize(2, 2);

    EXPECT_EQ(mtr1, mtr2);
}

TEST(RestructTests, ResizePlusMinus)
{
    Matrix<int> mtr1 = {{1, 2, 3}, {3, 4, 5}};
    Matrix<int> mtr2 = {{1, 2}, {3, 4}, {7, 7}};

    mtr1.resize(3, 2, 7);

    EXPECT_EQ(mtr1, mtr2);
}

TEST(RestructTests, InsertRowOK)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}, {5, 6}};
    Matrix<int> mtr2 = {{1, 2}, {7, 7}, {3, 4}, {5, 6}};

    mtr1.insert_row(1, 7);

    EXPECT_EQ(mtr1, mtr2);
}

TEST(RestructTests, InsertRowInitList)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}, {5, 6}};
    Matrix<int> mtr2 = {{1, 2}, {2, 5}, {3, 4}, {5, 6}};

    mtr1.insert_row(1, {2, 5});

    EXPECT_EQ(mtr1, mtr2);
}

TEST(RestructTests, InsertRowInitListEmpty)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(mtr1.insert_row(1, {}), InitializationError);
}

TEST(RestructTests, InsertColInitListEmpty)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(mtr1.insert_row(2, {}), InitializationError);
}

TEST(RestructTests, InsertRowDefaultFill)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}, {5, 6}};
    Matrix<int> mtr2 = {{1, 2}, {0, 0}, {3, 4}, {5, 6}};

    mtr1.insert_row(1);

    EXPECT_EQ(mtr1, mtr2);
}

TEST(RestructTests, InsertRowOutOfRangePlus)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(mtr1.insert_row(4, 7), IndexError);
}

TEST(RestructTests, InsertRowOutOfRangeMinus)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(mtr1.insert_row(-1, 7), IndexError);
}

TEST(RestructTests, InsertColOK)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}, {5, 6}};
    Matrix<int> mtr2 = {{1, 5, 2}, {3, 5, 4}, {5, 5, 6}};

    mtr1.insert_column(1, 5);

    EXPECT_EQ(mtr1, mtr2);
}

TEST(RestructTests, InsertColInitList)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}, {5, 6}};
    Matrix<int> mtr2 = {{1, 1, 2}, {3, 2, 4}, {5, 3, 6}};

    mtr1.insert_column(1, {1, 2, 3});

    EXPECT_EQ(mtr1, mtr2);
}

TEST(RestructTests, InsertColDefaultFill)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}, {5, 6}};
    Matrix<int> mtr2 = {{1, 0, 2}, {3, 0, 4}, {5, 0, 6}};

    mtr1.insert_column(1);

    EXPECT_EQ(mtr1, mtr2);
}

TEST(RestructTests, InsertColOutOfRangePlus)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(mtr1.insert_column(3, 7), IndexError);
}

TEST(RestructTests, InsertColOutOfRangeMinus)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(mtr1.insert_column(-3, 7), IndexError);
}

TEST(RestructTests, DeleteRowOK)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}, {5, 6}};
    Matrix<int> mtr2 = {{1, 2}, {5, 6}};

    mtr1.delete_row(1);

    EXPECT_EQ(mtr1, mtr2);
}

TEST(RestructTests, DeleteRowOutOfRangePlus)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(mtr1.delete_row(3), IndexError);
}

TEST(RestructTests, DeleteRowOutOfRangeMinus)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(mtr1.delete_row(-1), IndexError);
}

TEST(RestructTests, DeleteColOK)
{
    Matrix<int> mtr1 = {{1, 2, 3}, {3, 4, 5}, {5, 6, 7}};
    Matrix<int> mtr2 = {{1, 3}, {3, 5}, {5, 7}};

    mtr1.delete_column(1);

    EXPECT_EQ(mtr1, mtr2);
}

TEST(RestructTests, DeleteColOutOfRangePlus)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(mtr1.delete_column(3), IndexError);
}

TEST(RestructTests, DeleteColOutOfRangeMinus)
{
    Matrix<int> mtr1 = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_THROW(mtr1.delete_column(-1), IndexError);
}

TEST(RestructTests, IsSquare)
{
    Matrix<double> mtr1(5, 5);
    Matrix<char> mtr2(2, 3);

    EXPECT_TRUE(mtr1.is_square());
    EXPECT_FALSE(mtr2.is_square());
}

#endif // __TEST_MATRIX_RESTRUCT_INL__