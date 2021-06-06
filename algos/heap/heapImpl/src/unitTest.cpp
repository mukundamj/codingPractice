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
    std::cout << "\nThe vector contents before heapifying\n ";
    print();

    HeapUtils::makeHeap(m_vectorOfInt.begin(), m_vectorOfInt.end());

    std::cout << "\nThe vector contents after heapifying\n ";
    print();

    EXPECT_EQ(20, m_vectorOfInt.front());

    Heap<int> maxHeapOfInt(m_vectorOfInt);

    EXPECT_FALSE(maxHeapOfInt.empty());
    EXPECT_EQ(10, maxHeapOfInt.size());
    EXPECT_EQ(20, maxHeapOfInt.top());

    maxHeapOfInt.pop();
    EXPECT_EQ(14, maxHeapOfInt.top());

    maxHeapOfInt.push(50);
    EXPECT_EQ(50, maxHeapOfInt.top());

    maxHeapOfInt.push(40);
    EXPECT_EQ(50, maxHeapOfInt.top());

    maxHeapOfInt.emplace(100);
    EXPECT_EQ(100, maxHeapOfInt.top());

    Heap<int> maxHeapOfInt_2({23, 19, 35, 12, 11, 66, 17, 13});
    EXPECT_EQ(66, maxHeapOfInt_2.top());

    maxHeapOfInt.swap(maxHeapOfInt_2);
    EXPECT_EQ(66, maxHeapOfInt.top());
    EXPECT_EQ(100, maxHeapOfInt_2.top());

    std::cout << "===================================================" << std::endl;
}

TEST_F(HeapTestFixture, heapSort)
{
    std::cout << "===================================================" << std::endl;
    std::cout << "\nThe vector contents before heap sort\n ";
    print();

    HeapUtils::heapSort(m_vectorOfInt.begin(), m_vectorOfInt.end());

    std::cout << "\nThe vector contents after heap sort\n ";
    print();

    std::vector<int> sortedVectorOfInt{1, 2, 3, 7, 8, 9, 9, 14, 11, 20};
    EXPECT_EQ(m_vectorOfInt, sortedVectorOfInt);

    std::cout << "===================================================" << std::endl;
}
