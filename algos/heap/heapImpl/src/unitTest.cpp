#include <iostream>
#include "heap.h"
#include "gtest/gtest.h"

class HeapTestFixture: public testing::Test {

protected:

    void SetUp() override
    {
        m_vectorOfInt.push_back(7);
        m_vectorOfInt.push_back(2);
        m_vectorOfInt.push_back(9);
        m_vectorOfInt.push_back(3);
        m_vectorOfInt.push_back(8);
        m_vectorOfInt.push_back(1);
        m_vectorOfInt.push_back(14);
        m_vectorOfInt.push_back(20);
        m_vectorOfInt.push_back(11);
        m_vectorOfInt.push_back(9);
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

TEST_F(HeapTestFixture, makeHeap)
{
    std::cout << "===================================================" << std::endl;
    std::cout << "\nThe vector contents before heapifying\n ";
    print();

    HeapUtils::makeHeap(m_vectorOfInt.begin(), m_vectorOfInt.end());

    std::cout << "\nThe vector contents after heapifying\n ";
    print();
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
    std::cout << "===================================================" << std::endl;
}
