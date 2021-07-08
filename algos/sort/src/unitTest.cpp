#include <iostream>
#include "sorting.h"
#include "gtest/gtest.h"

class SortingTestFixture : public testing::Test {

protected:

    void SetUp() override
    {
    }

    void printVector(const std::vector<int>& numbers)
    {
        for(auto n : numbers) std::cout << n << " ";
        std::cout << std::endl;
    }
};

TEST_F(SortingTestFixture, countSmaller_testVector1)
{
    std::vector<int> testVector{0, 1};
    std::cout << "The input vector is: ";
    printVector(testVector);
    std::vector<int> expectedResultVector{0, 0};
    std::cout << "The expected result vector is: ";
    printVector(expectedResultVector);
    EXPECT_EQ(expectedResultVector, Sorting::countSmaller(testVector));
}

TEST_F(SortingTestFixture, countSmaller_testVector2)
{
    std::vector<int> testVector{1, 0};
    std::cout << "The input vector is: ";
    printVector(testVector);
    std::vector<int> expectedResultVector{1, 0};
    std::cout << "The expected result vector is: ";
    printVector(expectedResultVector);
    EXPECT_EQ(expectedResultVector, Sorting::countSmaller(testVector));
}

TEST_F(SortingTestFixture, countSmaller_testVector3)
{
    std::vector<int> testVector{100};
    std::cout << "The input vector is: ";
    printVector(testVector);
    std::vector<int> expectedResultVector{0};
    std::cout << "The expected result vector is: ";
    printVector(expectedResultVector);
    EXPECT_EQ(expectedResultVector, Sorting::countSmaller(testVector));
}

TEST_F(SortingTestFixture, countSmaller_testVector4)
{
    std::vector<int> testVector;
    std::cout << "The input vector is: ";
    printVector(testVector);
    std::vector<int> expectedResultVector;
    std::cout << "The expected result vector is: ";
    printVector(expectedResultVector);
    EXPECT_EQ(expectedResultVector, Sorting::countSmaller(testVector));
}

TEST_F(SortingTestFixture, countSmaller_testVector5)
{
    std::vector<int> testVector{6, 4, 1, 8, 7, 5, 2, 9};
    std::cout << "The input vector is: ";
    printVector(testVector);
    std::vector<int> expectedResultVector{4, 2, 0, 3, 2, 1, 0, 0};
    std::cout << "The expected result vector is: ";
    printVector(expectedResultVector);
    EXPECT_EQ(expectedResultVector, Sorting::countSmaller(testVector));
}

TEST_F(SortingTestFixture, countSmaller_testVector6)
{
    std::vector<int> testVector{20, 13, 8, 55, 8, 5, 71, 68, 19, 0, 105, 66, 5, 5, 13, 20};
    std::cout << "The input vector is: ";
    printVector(testVector);
    std::vector<int> expectedResultVector{9, 6, 4, 8, 4, 1, 8, 7, 4, 0, 5, 4, 0, 0, 0, 0};
    std::cout << "The expected result vector is: ";
    printVector(expectedResultVector);
    EXPECT_EQ(expectedResultVector, Sorting::countSmaller(testVector));
}
