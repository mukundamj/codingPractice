#include <iostream>
#include "BinarySearchTree.h"
#include "gtest/gtest.h"

class TreeTestFixture : public testing::Test {

protected:

    void SetUp() override
    {
        m_tree.bstInsert(10);
        m_tree.bstInsert(5);
        m_tree.bstInsert(12);
        m_tree.bstInsert(2);
        m_tree.bstInsert(14);
        m_tree.bstInsert(7);
        m_tree.bstInsert(6);
        m_tree.bstInsert(8);
    }

    void printTree()
    {
        std::cout << "\nPre order traversal\n";
        m_tree.preOrderTraversal();

        std::cout << "\nIn order traversal\n";
        m_tree.inOrderTraversal();

        std::cout << "\nPost order traversal\n";
        m_tree.postOrderTraversal();
    }

    Tree<int> m_tree;
};

TEST_F(TreeTestFixture, printGraph)
{
    printTree();
}

TEST_F(TreeTestFixture, bstSearchIterative)
{
    EXPECT_EQ(10, (m_tree.bstSearchIterative(10))->val);
    EXPECT_EQ(5, (m_tree.bstSearchIterative(5))->val);
    EXPECT_EQ(12, (m_tree.bstSearchIterative(12))->val);
    EXPECT_EQ(2, (m_tree.bstSearchIterative(2))->val);
    EXPECT_EQ(14, (m_tree.bstSearchIterative(14))->val);
    EXPECT_EQ(7, (m_tree.bstSearchIterative(7))->val);
    EXPECT_EQ(6, (m_tree.bstSearchIterative(6))->val);
    EXPECT_EQ(8, (m_tree.bstSearchIterative(8))->val);
    EXPECT_EQ(nullptr, m_tree.bstSearchIterative(20));

    m_tree.bstInsert(20);
    EXPECT_EQ(20, (m_tree.bstSearchIterative(20))->val);
}

TEST_F(TreeTestFixture, bstSearchRecursive)
{
    EXPECT_EQ(10, (m_tree.bstSearchRecursive(10))->val);
    EXPECT_EQ(5, (m_tree.bstSearchRecursive(5))->val);
    EXPECT_EQ(12, (m_tree.bstSearchRecursive(12))->val);
    EXPECT_EQ(2, (m_tree.bstSearchRecursive(2))->val);
    EXPECT_EQ(14, (m_tree.bstSearchRecursive(14))->val);
    EXPECT_EQ(7, (m_tree.bstSearchRecursive(7))->val);
    EXPECT_EQ(6, (m_tree.bstSearchRecursive(6))->val);
    EXPECT_EQ(8, (m_tree.bstSearchRecursive(8))->val);
    EXPECT_EQ(nullptr, m_tree.bstSearchRecursive(20));

    m_tree.bstInsert(20);
    EXPECT_EQ(20, (m_tree.bstSearchRecursive(20))->val);
}

TEST_F(TreeTestFixture, bstMinimum)
{
    EXPECT_EQ(2, (m_tree.bstMinimum())->val);
}

TEST_F(TreeTestFixture, bstMaximum)
{
    EXPECT_EQ(14, (m_tree.bstMaximum())->val);
}
