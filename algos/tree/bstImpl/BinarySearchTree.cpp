#include <iostream>
#include "BinarySearchTree.h"

void Tree<T>::PreOrderTraversal(TreeNode<T>* root) const
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

void Tree<T>::InOrderTraversal(TreeNode<T>* root) const
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

void Tree<T>::PostOrderTraversal(TreeNode<T>* root) const
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

TreeNode<T>* BinarySearchRecursiveTree<T>::SearchRecursive(TreeNode<T>* root, T val) const
{
    if(!root || root->val == val) return root;

    if(val < root->val) return SearchRecursive(root->left, val);

    else return SearchRecursive(root->right, val);
}

template<typename T>
TreeNode<T>*
BinarySearchTreeUtils<T>::Insert(TreeNode<T>* root, T val)
{
    if (!root)
    {
    	return new TreeNode<T>(val);
    }
    
    if (val < root->val)
    {
    	root->left = Insert(root->left, val);
    }
    
    else if (val > root->val)
    {
    	root->right = Insert(root->right, val);
    }
    
    return root;	
}

template<typename T>
TreeNode<T>*
BinarySearchTreeUtils<T>::Search(TreeNode<T>* root, T val)
{
	if (!root || (val == root->val)) return root;

	if (val < root->val)
	{
		return Search(root->left, val);
	}

	return Search(root->right, val);
}

template class BinarySearchTreeUtils<int>;
