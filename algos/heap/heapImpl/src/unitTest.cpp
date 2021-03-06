#include <iostream>
#include <deque>
#include "heap.h"
#include "gtest/gtest.h"

class HeapTestFixture: public testing::Test {

protected:

    void SetUp() override
    {
    }

    void print(const std::vector<int>& vectorOfInt) const
    {
        for(auto n : vectorOfInt)
        {
            std::cout << n << " ";
        }
        std::cout << "\n";
    }

    template<typename RandomIterator>
    void print(RandomIterator begin, RandomIterator end) const
    {
        while(begin != end)
        {
            std::cout << *begin << " ";
            begin++;
        }
        std::cout << "\n";
    }

};

TEST_F(HeapTestFixture, testingConstructorA)
{
    std::cout << "===================================================" << std::endl;
    std::cout << "The container contents before heapifying" << std::endl;
    std::vector<int> vectorOfInt{7, 2, 9, 3, 8, 1, 14, 20, 11, 9};
    print(vectorOfInt);

    Heap<int> maxHeapOfInt(vectorOfInt);
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

TEST_F(HeapTestFixture, testingConstructorB)
{
    std::cout << "===================================================" << std::endl;
    std::cout << "The container contents before heapifying" << std::endl;
    print({7, 2, 9, 3, 8, 1, 14, 20, 11, 9});

    Heap<int> maxHeapOfInt({7, 2, 9, 3, 8, 1, 14, 20, 11, 9});
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

TEST_F(HeapTestFixture, testingConstructorC)
{
    std::cout << "===================================================" << std::endl;
    std::vector<int> vectorOfInt1{7, 2, 9, 3, 8};
    std::vector<int> vectorOfInt2{1, 14, 20, 11, 9};
    std::cout << "The two partial container contents before heapifying" << std::endl;
    print(vectorOfInt2);
    print(vectorOfInt1);

    Heap<int> maxHeapOfInt(vectorOfInt1.begin(), vectorOfInt1.end(), vectorOfInt2);
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

TEST_F(HeapTestFixture, testingConstructorD)
{
    std::cout << "===================================================" << std::endl;
    std::vector<int> vectorOfInt1{7, 2, 9, 3, 8};
    std::cout << "The partial container contents before heapifying" << std::endl;
    print(vectorOfInt1);

    Heap<int> maxHeapOfInt(vectorOfInt1.begin(), vectorOfInt1.end(), {1, 14, 20, 11, 9});
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

TEST_F(HeapTestFixture, testingConstructorAWithDequeContainer)
{
    std::cout << "===================================================" << std::endl;
    std::deque<int> dequeOfInt{7, 2, 9, 3, 8, 1, 14, 20, 11, 9};
    std::cout << "The container contents before heapifying" << std::endl;
    print(dequeOfInt.cbegin(), dequeOfInt.cend());

    Heap<int, std::deque<int>> maxHeapOfInt(dequeOfInt);
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

    std::deque<int> dequeOfInt2{23, 19, 35, 12, 11, 66, 17, 13};
    Heap<int, std::deque<int>> maxHeapOfInt2(dequeOfInt2);
    EXPECT_EQ(66, maxHeapOfInt2.top());

    maxHeapOfInt.swap(maxHeapOfInt2);
    EXPECT_EQ(66, maxHeapOfInt.top());
    EXPECT_EQ(100, maxHeapOfInt2.top());
    std::cout << "The container contents after swapping" << std::endl;
    maxHeapOfInt.print();

    std::cout << "===================================================" << std::endl;
}


TEST_F(HeapTestFixture, heapSort)
{
    std::cout << "===================================================" << std::endl;
    std::vector<int> vectorOfInt{7, 2, 9, 3, 8, 1, 14, 20, 11, 9};
    std::cout << "The container contents before sorting" << std::endl;
    print(vectorOfInt);

    HeapUtils::heapSort(vectorOfInt.begin(), vectorOfInt.end());
    std::vector<int> sortedVectorOfInt{1, 2, 3, 7, 8, 9, 9, 11, 14, 20};
    EXPECT_EQ(sortedVectorOfInt, vectorOfInt);
    std::cout << "The container contents after sorting" << std::endl;
    print(vectorOfInt);
    std::cout << "===================================================" << std::endl;
}
