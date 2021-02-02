#include "TreeUtils.h"

template<typename T>
const TreeNode<T>*
TreeUtils<T>::Clone(const TreeNode<T>* root)
{
	if (!root) return root;

	TreeNode<T>* clonedRoot = new TreeNode<T>(root->val);	
	TreeNode<T>* ret = clonedRoot;

	PreOrderTraversalCloning(root, clonedRoot);

	return ret;
}

template<typename T>
void
TreeUtils<T>::PreOrderTraversalCloning(const TreeNode<T>* root, TreeNode<T>* clonedRoot)
{
	if(root->left)
	{
		clonedRoot->left = new TreeNode<T>(root->left->val);
		PreOrderTraversalCloning(root->left, clonedRoot->left);
	}

	if(root->right)
	{
		clonedRoot->right = new TreeNode<T>(root->right->val);
		PreOrderTraversalCloning(root->right, clonedRoot->right);
	}
}

template<typename T>
std::string
TreeUtils<T>::InOrderTraversalPrint(const TreeNode<T>* root)
{
	std::ostringstream oStringStream;

	oStringStream << "[ ";

	InOrderTraversalPrint(root, oStringStream);

	oStringStream << "]";

	return oStringStream.str();
}

template<typename T>
void
TreeUtils<T>::InOrderTraversalPrint(const TreeNode<T>* root, std::ostringstream& oStringStream)
{
	if(!root) return;
	
	if(root->left)
	{
		InOrderTraversalPrint(root->left, oStringStream);
	}

	oStringStream << root->val << " ";
	
	if(root->right)
	{
		InOrderTraversalPrint(root->right, oStringStream);
	}
}

template<typename T>
std::string
TreeUtils<T>::PreOrderTraversalPrint(const TreeNode<T>* root)
{
	std::ostringstream oStringStream;

	oStringStream << "[ ";

	PreOrderTraversalPrint(root, oStringStream);

	oStringStream << "]";

	return oStringStream.str();
}

template<typename T>
void
TreeUtils<T>::PreOrderTraversalPrint(const TreeNode<T>* root, std::ostringstream& oStringStream)
{
	if(!root) return;

	oStringStream << root->val << " ";
	
	if(root->left)
	{
		PreOrderTraversalPrint(root->left, oStringStream);
	}
	
	if(root->right)
	{
		PreOrderTraversalPrint(root->right, oStringStream);
	}
}

template class TreeUtils<int>;
