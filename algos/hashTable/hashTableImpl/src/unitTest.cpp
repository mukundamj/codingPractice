#include <iostream>
#include "hashTable.h"
#include "gtest/gtest.h"

class HashTableTestFixture : public testing::Test {

protected:

    void SetUp() override
    {
        m_hashTable.Insert(std::make_pair(0, "zero"));
        m_hashTable.Insert(std::make_pair(1, "one"));
        m_hashTable.Insert(std::make_pair(2, "two"));
        m_hashTable.Insert(std::make_pair(3, "three"));
        m_hashTable.Insert(std::make_pair(4, "four"));
        m_hashTable.Insert(std::make_pair(5, "five"));
        m_hashTable.Insert(std::make_pair(6, "six"));
        m_hashTable.Insert(std::make_pair(7, "seven"));
        m_hashTable.Insert(std::make_pair(8, "eight"));
        m_hashTable.Insert(std::make_pair(9, "nine"));
        m_hashTable.Insert(std::make_pair(10, "ten"));
        m_hashTable.Insert(std::make_pair(11, "twelve"));
        m_hashTable.Insert(std::make_pair(12, "twelve"));
        m_hashTable.Insert(std::make_pair(13, "thirteen"));
    }

    void printHashTable()
    {
        m_hashTable.Print();
    }

    HashTable<std::string> m_hashTable{5};
};

TEST_F(HashTableTestFixture, searchOperation)
{
    std::cout << "\n===================================================\n" << std::endl;
    std::cout << "This is how the original hash table looks like" << std::endl;
    printHashTable();

    EXPECT_TRUE(m_hashTable.Search(0));
    EXPECT_TRUE(m_hashTable.Search(1));
    EXPECT_TRUE(m_hashTable.Search(2));
    EXPECT_TRUE(m_hashTable.Search(3));
    EXPECT_TRUE(m_hashTable.Search(4));
    EXPECT_TRUE(m_hashTable.Search(5));
    EXPECT_TRUE(m_hashTable.Search(6));
    EXPECT_TRUE(m_hashTable.Search(7));
    EXPECT_TRUE(m_hashTable.Search(8));
    EXPECT_TRUE(m_hashTable.Search(9));
    EXPECT_TRUE(m_hashTable.Search(10));
    EXPECT_TRUE(m_hashTable.Search(11));
    EXPECT_TRUE(m_hashTable.Search(12));
    EXPECT_TRUE(m_hashTable.Search(13));
    EXPECT_FALSE(m_hashTable.Search(100));
}

TEST_F(HashTableTestFixture, deleteOperation)
{
    m_hashTable.Delete(0);
    m_hashTable.Delete(10);

    std::cout << "\n===================================================\n" << std::endl;
    std::cout << "After deleting 0 and 10 the hash table looks as below" << std::endl;
    printHashTable();

    EXPECT_FALSE(m_hashTable.Search(0));
    EXPECT_TRUE(m_hashTable.Search(1));
    EXPECT_TRUE(m_hashTable.Search(2));
    EXPECT_TRUE(m_hashTable.Search(3));
    EXPECT_TRUE(m_hashTable.Search(4));
    EXPECT_TRUE(m_hashTable.Search(5));
    EXPECT_TRUE(m_hashTable.Search(6));
    EXPECT_TRUE(m_hashTable.Search(7));
    EXPECT_TRUE(m_hashTable.Search(8));
    EXPECT_TRUE(m_hashTable.Search(9));
    EXPECT_FALSE(m_hashTable.Search(10));
    EXPECT_TRUE(m_hashTable.Search(11));
    EXPECT_TRUE(m_hashTable.Search(12));
    EXPECT_TRUE(m_hashTable.Search(13));
    EXPECT_FALSE(m_hashTable.Search(100));
}

TEST_F(HashTableTestFixture, insertOperation)
{
    m_hashTable.Insert(std::make_pair(12, "twelve"));
    m_hashTable.Insert(std::make_pair(13, "thirteen"));
    m_hashTable.Insert(std::make_pair(15, "fifteen"));
    m_hashTable.Insert(std::make_pair(100, "hundred"));

    std::cout << "\n===================================================\n" << std::endl;
    std::cout << "After adding 12, 13, 15 and 100 the hash table looks as below" << std::endl;
    printHashTable();

    EXPECT_TRUE(m_hashTable.Search(0));
    EXPECT_TRUE(m_hashTable.Search(1));
    EXPECT_TRUE(m_hashTable.Search(2));
    EXPECT_TRUE(m_hashTable.Search(3));
    EXPECT_TRUE(m_hashTable.Search(4));
    EXPECT_TRUE(m_hashTable.Search(5));
    EXPECT_TRUE(m_hashTable.Search(6));
    EXPECT_TRUE(m_hashTable.Search(7));
    EXPECT_TRUE(m_hashTable.Search(8));
    EXPECT_TRUE(m_hashTable.Search(9));
    EXPECT_TRUE(m_hashTable.Search(10));
    EXPECT_TRUE(m_hashTable.Search(11));
    EXPECT_TRUE(m_hashTable.Search(12));
    EXPECT_TRUE(m_hashTable.Search(13));
    EXPECT_TRUE(m_hashTable.Search(15));
    EXPECT_TRUE(m_hashTable.Search(100));
}
