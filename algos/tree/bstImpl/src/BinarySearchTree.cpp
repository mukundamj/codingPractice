#include <iostream>
#include "BinarySearchTree.h"


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
