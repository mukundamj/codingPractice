#include <iostream>
#include "heap.h"
#include "gtest/gtest.h"

class HeapTestFixture: public testing::Test {

protected:

    void SetUp() override
    {
        m_vectorOfInt.push_back(1);
        m_vectorOfInt.push_back(2);
        m_vectorOfInt.push_back(3);
        m_vectorOfInt.push_back(4);
        m_vectorOfInt.push_back(5);
        m_vectorOfInt.push_back(6);
        m_vectorOfInt.push_back(7);
        m_vectorOfInt.push_back(8);
        m_vectorOfInt.push_back(9);
        m_vectorOfInt.push_back(10);
    }

    void print() const
    {
        for(auto n : m_vectorOfInt)
        {
            std::cout << n << " ";
        }
        std::cout << "\n";
    }

    std::vector<int> m_vectorOfInt;
};


//void heap_sort(...)

TEST_F(HeapTestFixture, makeHeap)
{
    std::cout << "\n===================================================\n" << std::endl;
    std::cout << "\nThe vector contents before heapifying\n ";
    print();

    HeapUtils::makeHeap(m_vectorOfInt.begin(), m_vectorOfInt.end());

    std::cout << "\nThe vector contents after heapifying\n ";
    print();
}
