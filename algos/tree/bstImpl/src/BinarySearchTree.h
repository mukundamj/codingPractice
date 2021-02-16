//#pragma once directive asks the compiler to include a header file only a single time,
//no matter how many times it has been imported. It's equivalent to an include guard that
//prevents the file from being processed multiple times.
//Source of above info: https://www.cprogramming.com/reference/preprocessor/pragma.html
#pragma once

template<typename T = int>
struct TreeNode
{
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T x) : val(x), left(NULL), right(NULL) {}
};

template<typename T = int>
class Tree
{
public:
    Tree() : m_root(NULL) {}

    /*Time complexity T(n) = O(n), where n is number of nodes in the tree*/
    void PreOrderTraversal() const
    {
        PreOrderTraversal(m_root);
    }

    /*If the tree is a binary search tree then inorder tree traversal allows us to print
    the keys in a sorted order.
    Time complexity T(n) = O(n), where n is number of nodes in the tree*/
    void InOrderTraversal() const
    {
        InOrderTraversal(m_root);
    }

    /*Time complexity T(n) = O(n), where n is number of nodes in the tree*/
    void PostOrderTraversal() const
    {
        PostOrderTraversal(m_root);
    }

    /*TBD*/
    //void Clone(const TreeNode<T>* root) const;

protected:
    TreeNode<T>* m_root;

private:
    void PreOrderTraversal(const TreeNode<T>* root) const;
    void InOrderTraversal(const TreeNode<T>* root) const;
    void PostOrderTraversal(const TreeNode<T>* root) const;
};

/*The keys in a binary search tree are always stored in such a way as to satisfy the
binary-search-tree property: left-node-key ≤ parent-node-key ≤ right-node-key 
*/
template<typename T = int>
class BinarySearchTree : public Tree<T>
{
public:
    /*
      The following implementation uses recursive approach.
      Time complexity for a tree having n nodes is O(n).
      Iterative approach is TBD 
    */
    void Insert(const T& val);

    /*
       TBD: Deleting a node is a tricky opration; it will
       be dealt with later.
    */ 
    void Delete(const T& val);

    /* Time complexity T(n) = O(h)*/
    const TreeNode<T>* SearchRecursive(const T& val) const;

    /* Time complexity T(n) = O(h)*/
    const TreeNode<T>* SearchIterative(const T& val) const;

    /* Time complexity T(n) = O(h)*/
    const TreeNode<T>* Minimum() const;

    /* Time complexity T(n) = O(h)*/
    const TreeNode<T>* Maximum() const;

    const TreeNode<T>* Successor(const TreeNode<T>* x) const;
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

    const TreeNode<T>* Predecessor(const TreeNode<T>* x) const;
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

private:
    const TreeNode<T>* SearchRecursive(const TreeNode<T>* root, const T& val) const;
    TreeNode<T>* Insert(TreeNode<T>* root, const T& val);
};

/*
    While using templates, declaration and definition should be in one header file.
    Compiler won't generate a machine code for a particular template instantiation
    if it's not used in the client code. In the client code only BinarySearchTree.h
    will be included, hence it should contain both declaration and definition. 
*/
template <typename T>
void Tree<T>::PreOrderTraversal(const TreeNode<T>* root) const
{
    if(!root) return;

    std::cout << root->val << std::endl;

    if(root->left)
    {
        PreOrderTraversal(root->left);
    }
 
    if(root->right)
    {
        PreOrderTraversal(root->right);
    }
}

template <typename T>
void Tree<T>::InOrderTraversal(const TreeNode<T>* root) const
{
    if(!root) return;

    if(root->left)
    {
        InOrderTraversal(root->left);
    }

    std::cout << root->val << std::endl;

    if(root->right)
    {
        InOrderTraversal(root->right);
    }
}

template <typename T>
void Tree<T>::PostOrderTraversal(const TreeNode<T>* root) const
{
    if(!root) return;

    if(root->left)
    {
        PostOrderTraversal(root->left);
    }

    if(root->right)
    {
        PostOrderTraversal(root->right);
    }

    std::cout << root->val << std::endl;
}

template <typename T>
const TreeNode<T>* BinarySearchTree<T>::SearchRecursive(const T& val) const
{
    return SearchRecursive(Tree<T>::m_root, val);
}

template <typename T>
const TreeNode<T>* BinarySearchTree<T>::SearchRecursive(const TreeNode<T>* root, const T& val) const
{
    if(!root || root->val == val) return root;

    if(val < root->val) return SearchRecursive(root->left, val);

    else return SearchRecursive(root->right, val);
}

template <typename T>
const TreeNode<T>* BinarySearchTree<T>::SearchIterative(const T& val) const
{
    TreeNode<T>* root = Tree<T>::m_root;
    while(root && val != root->val)
    {
        if(val < root->val) root = root->left;
        else root = root->right;
    }

    return root;
}

template <typename T>
const TreeNode<T>* BinarySearchTree<T>::Minimum() const
{
    TreeNode<T>* root = Tree<T>::m_root;

    while(root && root->left)
    {
        root = root->left;
    }

    return root;
}

template <typename T>
const TreeNode<T>* BinarySearchTree<T>::Maximum() const
{
    TreeNode<T>* root = Tree<T>::m_root;

    while(root && root->right)
    {
        root = root->right;
    }

    return root;
}

template <typename T>
void BinarySearchTree<T>::Insert(const T& val)
{
    Tree<T>::m_root = Insert(Tree<T>::m_root, val);
}

template <typename T>
TreeNode<T>* BinarySearchTree<T>::Insert(TreeNode<T>* root, const T& val)
{
    if (!root)
    {
        return new TreeNode<T>(val);
    }

    if (val <= root->val)
    {
        root->left = Insert(root->left, val);
    }

    else
    {
        root->right = Insert(root->right, val);
    }

    return root;
}
