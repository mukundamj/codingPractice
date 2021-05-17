//#pragma once directive asks the compiler to include a header file only a single time,
//no matter how many times it has been imported. It's equivalent to an include guard that
//prevents the file from being processed multiple times.
//Source of above info: https://www.cprogramming.com/reference/preprocessor/pragma.html
#pragma once

namespace TreeUtils
{

template<typename T = int>
struct TreeNode
{
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T x) : val(x), left(NULL), right(NULL) {}
};

/*Time complexity T(n) = O(n), where n is number of nodes in the tree*/
template <typename T = int>
void preOrderTraversal(const TreeNode<T>* root)
{
    if(!root) return;

    std::cout << root->val << std::endl;

    preOrderTraversal(root->left);
 
    preOrderTraversal(root->right);
}

/*If the tree is a binary search tree then inorder tree traversal allows us to print
the keys in a sorted order.
Time complexity T(n) = O(n), where n is number of nodes in the tree*/
template <typename T = int>
void inOrderTraversal(const TreeNode<T>* root)
{
    if(!root) return;

    inOrderTraversal(root->left);

    std::cout << root->val << std::endl;

    inOrderTraversal(root->right);
}

/*Time complexity T(n) = O(n), where n is number of nodes in the tree*/
template <typename T = int>
void postOrderTraversal(const TreeNode<T>* root)
{
    if(!root) return;

    postOrderTraversal(root->left);

    postOrderTraversal(root->right);

    std::cout << root->val << std::endl;
}

/*TBD*/
//void Clone(const TreeNode<T>* root) const;

/*The keys in a binary search tree are always stored in such a way as to satisfy the
binary-search-tree property: left-node-key ≤ parent-node-key ≤ right-node-key 
*/

/*
  The following implementation uses recursive approach.
  Time complexity for a tree having n nodes is O(n).
  Iterative approach is TBD 
*/
template<typename T = int>
TreeNode<T>* bstInsert(TreeNode<T>* root, const T& val)
{
    if (!root)
    {
        return new TreeNode<T>(val);
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
*/ 
//void bstDelete(const T& val);

/* Time complexity T(n) = O(h)*/
template <typename T = int>
const TreeNode<T>* bstSearchRecursive(const TreeNode<T>* root, const T& val)
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
template <typename T = int>
const TreeNode<T>* bstSearchIterative(const TreeNode<T>* root, const T& val)
{
    while(root && val != root->val)
    {
        if(val < root->val) root = root->left;
        else root = root->right;
    }

    return root;
}

/*Time complexity T(n) = O(h)*/
template <typename T = int>
const TreeNode<T>* bstMinimum(const TreeNode<T>* root)
{
    while(root && root->left)
    {
        root = root->left;
    }

    return root;
}

/* Time complexity T(n) = O(h)*/
template <typename T = int>
const TreeNode<T>* bstMaximum(const TreeNode<T>* root)
{
    while(root && root->right)
    {
        root = root->right;
    }

    return root;
}

template <typename T = int>
TreeNode<T>* bstSuccessor(const TreeNode<T>* x);
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

template <typename T = int>
TreeNode<T>* bstPredecessor(const TreeNode<T>* x);
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
}
