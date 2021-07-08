//#pragma once directive asks the compiler to include a header file only a single time,
//no matter how many times it has been imported. It's equivalent to an include guard that
//prevents the file from being processed multiple times.
//Source of above info: https://www.cprogramming.com/reference/preprocessor/pragma.html
#pragma once

#include <math.h>

namespace TreeUtils
{

template<typename T = int>
struct Node
{
    T val;
    Node<T>* left;
    Node<T>* right;
    Node(T x) : val(x), left(nullptr), right(nullptr) {}
};

/*
 For destroying a tree structure postOrderTraversal is used because the child
 nodes must be destroyed before destroying the parent node.
 Time complexity T(n) = O(n), where n is number of nodes in the tree.
*/
template<typename T = int>
void destroyRecursively(Node<T>* root)
{
    if (root == nullptr) return;
    destroyRecursively(root->left);
    destroyRecursively(root->right);
    std::cout << root->val << " ";
    delete root;
}

/*Time complexity T(n) = O(n), where n is number of nodes in the tree*/
template<typename T = int>
void preOrderTraversal(const Node<T>* root)
{
    if(!root) return;

    std::cout << root->val << " ";

    preOrderTraversal(root->left);
 
    preOrderTraversal(root->right);
}

/*If the tree is a binary search tree then inorder tree traversal allows us to print
the keys in a sorted order.
Time complexity T(n) = O(n), where n is number of nodes in the tree*/
template<typename T = int>
void inOrderTraversal(const Node<T>* root)
{
    if(!root) return;

    inOrderTraversal(root->left);

    std::cout << root->val << " ";

    inOrderTraversal(root->right);
}

/*Time complexity T(n) = O(n), where n is number of nodes in the tree*/
template<typename T = int>
void postOrderTraversal(const Node<T>* root)
{
    if(!root) return;

    postOrderTraversal(root->left);

    postOrderTraversal(root->right);

    std::cout << root->val << " ";
}

/*TBD*/
//void Clone(const Node<T>* root) const;

/*The keys in a binary search tree are always stored in such a way as to satisfy the
binary-search-tree property: left-node-key ≤ parent-node-key ≤ right-node-key 
*/

/*
  The following implementation uses recursive approach.
  Time complexity for a tree having n nodes is O(n).
  Iterative approach is TBD 
*/
template<typename T = int>
Node<T>* bstInsert(Node<T>* root, const T& val)
{
    if (!root)
    {
        return new Node<T>(val);
    }

    if (val <= root->val)
    {
        root->left = bstInsert(root->left, val);
    }

    else
    {
        root->right = bstInsert(root->right, val);
    }

    return root;
}

/*
 TBD: Deleting a node is a tricky opration; it will
 be dealt with later.

 void bstDelete(const T& val);
*/ 

/* Time complexity T(n) = O(h)*/
template<typename T = int>
const Node<T>* bstSearchRecursive(const Node<T>* root, const T& val)
{
    if(!root || root->val == val) return root;

    if(val < root->val)
    {
        return bstSearchRecursive(root->left, val);
    }

    else
    {
        return bstSearchRecursive(root->right, val);
    }
}

/* Time complexity T(n) = O(h)*/
template<typename T = int>
const Node<T>* bstSearchIterative(const Node<T>* root, const T& val)
{
    while(root && val != root->val)
    {
        if(val < root->val) root = root->left;
        else root = root->right;
    }

    return root;
}

/*Time complexity T(n) = O(h)*/
template<typename T = int>
const Node<T>* bstMinimum(const Node<T>* root)
{
    while(root && root->left)
    {
        root = root->left;
    }

    return root;
}

/* Time complexity T(n) = O(h)*/
template<typename T = int>
const Node<T>* bstMaximum(const Node<T>* root)
{
    while(root && root->right)
    {
        root = root->right;
    }

    return root;
}

template<typename T = int>
Node<T>* bstSuccessor(const Node<T>* x);
/*
    Refer to the page number 292 in the book, "Introduction To Algorithms"
    3rd edition, for solution. Here is the pseudocode:

    TREE-SUCCESSOR (x)
    //If the node has a right child then the minimum in the right sub-tree will be the successor 
    1 if x.right != NIL
    2     return TREE-MINIMUM(x.right)
    //If the node doesn't have a right child then find the nearest ancestor node
    //that has this node in the left sub-tree 
    3 y = x.p
    4 while y != NIL and x == y.right
    5    x = y
    6    y = x.p
    7 return y

    In the below example if x is :
        - 10 then 12 is the successor
        - 5 or 7 or 8 then 10 is the successor, because it is nearest ancestor node that has
          8 in its left sub-tree
        - 2 then 5 is the successor
    
              10
             /  \
            5    12
           / \
          2   7
             / \
            6   8

    The running time of the above algorithm on a tree of height h is O(h). The above algorithm
    assumes that the node x has a parent node.
*/

template<typename T = int>
Node<T>* bstPredecessor(const Node<T>* x);
/*
    The algorithm is similar to the one above

    TREE-PREDECESSOR (x)
    1 if x.left != NIL
    2     return TREE-MAXIMUM(x.left)
    3 y = x.p
    4 while y != NIL and x == y.left
    5    x = y
    6    y = x.p
    7 return y
*/

/*
 This function returns the total number of nodes in a complete binary tree. This algorithm is
 not specific to binary search trees, but any binary tree which fulfills the definition of a
 complete binary tree. As per definition a complete binary tree is the one where all tree
 levels are completely filled except the last level and the last level has all the keys
 as far left as possible.

 The time complexity of this algorithm T(n) = O(h), where h is the height of the tree
*/

template<typename T = int>
uint32_t countNumberOfNodesInCompleteBinaryTree(const Node<T>* root)
{
    if(!root) return 0;

    uint32_t leftHeight = 0;
    uint32_t rightHeight = 0;
    const Node<T>* leftNode = root;
    const Node<T>* rightNode = root;

    while(leftNode && leftNode->left)
    {
        leftHeight++;
        leftNode = leftNode->left;
    }

    while(rightNode && rightNode->right)
    {
        rightHeight++;
        rightNode = rightNode->right;
    }

    if(leftHeight == rightHeight)
    {
        return (std::pow(2, leftHeight + 1) - 1);
    }
    else
    {
        return 1 + countNumberOfNodesInCompleteBinaryTree(root->left) + countNumberOfNodesInCompleteBinaryTree(root->right); 
    }
}

template<typename T = int>
uint32_t countNumberOfNodesInAnyBinaryTree(const Node<T>* root)
{
    uint32_t numOfNodes = 0;
    countNumberOfNodesInAnyBinaryTree(root, numOfNodes);
    return numOfNodes;
}

template<typename T = int>
void countNumberOfNodesInAnyBinaryTree(const Node<T>* root, uint32_t& numOfNodes)
{
    if(!root) return;
    numOfNodes++;
    countNumberOfNodesInAnyBinaryTree(root->left, numOfNodes);
    countNumberOfNodesInAnyBinaryTree(root->right, numOfNodes);
}

}

/*
If memory for TreeUtils::Node<T> is allocated in heap then the client has to take care
of deleting it. To avoid the responsibility on the client the Tree class can be used.
When the class Tree is destroyed the Node is deallocated in Tree's destructor.
*/
template<typename T>
class Tree {
public:

    Tree() : m_root(nullptr)
    {}

    Tree(const T val): m_root(new TreeUtils::Node<T>(val))
    {}

    virtual ~Tree()
    {
        std::cout << "\nDestroying the nodes recursively\n";
        TreeUtils::destroyRecursively(m_root);
        std::cout << "\n";
    }

    void bstInsert(const T val)
    {
        m_root = TreeUtils::bstInsert(m_root, val);
    }

    void preOrderTraversal()
    {
        TreeUtils::preOrderTraversal(m_root); 
    }

    void inOrderTraversal()
    {
        TreeUtils::inOrderTraversal(m_root); 
    }

    void postOrderTraversal()
    {
        TreeUtils::postOrderTraversal(m_root); 
    }

    const TreeUtils::Node<T>* bstSearchIterative(const T val)
    {
        return TreeUtils::bstSearchIterative(m_root, val);
    }

    const TreeUtils::Node<T>* bstSearchRecursive(const T val)
    {
        return TreeUtils::bstSearchRecursive(m_root, val);
    }

    const TreeUtils::Node<T>* bstMinimum() const
    {
        return TreeUtils::bstMinimum(m_root);
    }

    const TreeUtils::Node<T>* bstMaximum() const
    {
        return TreeUtils::bstMaximum(m_root);
    }

    const uint32_t countNumberOfNodesInCompleteBinaryTree() const
    {
        return TreeUtils::countNumberOfNodesInCompleteBinaryTree(m_root);
    }

    const uint32_t countNumberOfNodesInAnyBinaryTree() const
    {
        return TreeUtils::countNumberOfNodesInAnyBinaryTree(m_root);
    }



private:

    TreeUtils::Node<T>* m_root;
};
