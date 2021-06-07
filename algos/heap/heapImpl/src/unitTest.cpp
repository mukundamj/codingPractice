#include <iostream>
#include "heap.h"
#include "gtest/gtest.h"

class HeapTestFixture: public testing::Test {

protected:

    void SetUp() override
    {
    }

    void print() const
    {
        for(auto n : m_vectorOfInt)
        {
            std::cout << n << " ";
        }
        std::cout << "\n";
    }

    std::vector<int> m_vectorOfInt{7, 2, 9, 3, 8, 1, 14, 20, 11, 9};
};

TEST_F(HeapTestFixture, makeHeap)
{
    std::cout << "===================================================" << std::endl;
    std::cout << "The container contents before heapifying" << std::endl;
    print();

    Heap<int> maxHeapOfInt(m_vectorOfInt);
    std::cout << "The container contents after heapifying" << std::endl;
    maxHeapOfInt.print();

    EXPECT_FALSE(maxHeapOfInt.empty());
    EXPECT_EQ(10, maxHeapOfInt.size());
    EXPECT_EQ(20, maxHeapOfInt.top());

    maxHeapOfInt.pop();
    EXPECT_EQ(14, maxHeapOfInt.top());
    std::cout << "The container contents after popping" << std::endl;
    maxHeapOfInt.print();

    maxHeapOfInt.push(50);
    EXPECT_EQ(50, maxHeapOfInt.top());
    std::cout << "The container contents after pushing 50" << std::endl;
    maxHeapOfInt.print();

    maxHeapOfInt.push(40);
    EXPECT_EQ(50, maxHeapOfInt.top());
    std::cout << "The container contents after pushing 40(rvalue)" << std::endl;
    maxHeapOfInt.print();

    int x = 51;
    maxHeapOfInt.push(x);
    EXPECT_EQ(51, maxHeapOfInt.top());
    std::cout << "The container contents after pushing 51(lvalue)" << std::endl;
    maxHeapOfInt.print();

    maxHeapOfInt.emplace(100);
    EXPECT_EQ(100, maxHeapOfInt.top());
    std::cout << "The container contents after emplacing 100" << std::endl;
    maxHeapOfInt.print();

    Heap<int> maxHeapOfInt_2({23, 19, 35, 12, 11, 66, 17, 13});
    EXPECT_EQ(66, maxHeapOfInt_2.top());

    maxHeapOfInt.swap(maxHeapOfInt_2);
    EXPECT_EQ(66, maxHeapOfInt.top());
    EXPECT_EQ(100, maxHeapOfInt_2.top());
    std::cout << "The container contents after swapping" << std::endl;
    maxHeapOfInt.print();
    std::cout << "===================================================" << std::endl;
}

TEST_F(HeapTestFixture, heapSort)
{
}
