#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>
#include "tree_algorithms.hpp"

template<class T>
BST<T>& BST<T>::operator= (const BST<T>& bst)
{
  if (this == &bst) return *this;
  tree_node<T> *root;
  root = bst.m_root;
  if (!root) this->m_root = NULL;
  else
  {
    vector<tree_node<T> *> queue;
    queue.push_back(root);
    unordered_map<int, tree_node<T>*> map;
    map[root->val] = new tree_node<T>(root->val);

    while (!queue.empty())
    {
      auto r = queue.back();
      queue.pop_back();
      tree_node<T> *clone_root = map[r->val];
      if (r->left)
      {
        tree_node<T> *left = new tree_node<T>(r->left->val);
        queue.push_back(r->left);
        clone_root->left = left;
        map[left->val] = left;
      }
      if (r->right)
      {
        tree_node<T> *right = new tree_node<T>(r->right->val);
        queue.push_back(r->right);
        clone_root->right = right;
        map[right->val] = right;
      }
    }
    this->m_root = map[root->val];
  }
  return *this;
}

/*
  Time complexity = O(log(n)), where n is number of nodes in the tree
*/
template<class T>
tree_node<T>* BST<T>::insert_node(tree_node<T> *root, const T val)
{
  if (!root)
  {
    return new tree_node<T>(val);
  }

  if (val < root->val)
  {
    root->left = insert_node(root->left, val);
  }

  else if (val > root->val)
  {
    root->right = insert_node(root->right, val);
  }

  return root;
}

/*
  Time complexity = O(log(n)), where n is number of nodes in the tree
*/
template<class T>
const tree_node<T>* BST<T>::search_node(const tree_node<T> *root, const T val)
{
  if (!root || root->val == val) return root;
  
  if (val < root->val)
  {
    return search_node(root->left, val);
  }

  return search_node(root->right, val);
}

/*
  Time complexity = O(n), where n is number of nodes in the tree
*/
template<class T>
void BST<T>::print_tree_helper(const tree_node<T> *root)
{
  if (!root) return;
  print_tree_helper(root->left);
  cout << root->val << " ";
  print_tree_helper(root->right);
  return;
}

template<class T>
void BST<T>::print_tree_overload(ostream &out, const tree_node<T> *root) const
{
  if (!root) return;
  print_tree_overload(out, root->left);
  out << root->val << " ";
  print_tree_overload(out, root->right);
  return;
}

/*
  Time complexity = O(n), where n is number of nodes in the tree
*/
template<class T>
void BST<T>::delete_tree(tree_node<T> *root)
{
  if (root)
  {
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
  }
}

int main(int argc, const char *argv[])
{
  BST<int> my_int_tree;

  my_int_tree.insert_node(5);
  my_int_tree.insert_node(2);
  my_int_tree.insert_node(8);
  my_int_tree.insert_node(1);
  my_int_tree.insert_node(3);
  my_int_tree.insert_node(7);
  my_int_tree.insert_node(9);
  my_int_tree.insert_node(0);
  my_int_tree.insert_node(4);
  my_int_tree.insert_node(6);
  my_int_tree.insert_node(10);

  cout << "Inorder traversal of the tree is\n";
  my_int_tree.print_tree();
  cout << "\nPrinting again using operator overloading\n";
  cout << my_int_tree;
  cout << "\n";

  if (my_int_tree.search_node(10))
    cout << "10 is found in the tree\n";
  else 
    cout << "10 is not found in the tree\n";

  if (my_int_tree.search_node(-1))
    cout << "-1 is found in the tree\n";
  else 
    cout << "-1 is not found in the tree\n";

  {
    BST<int> my_second_int_tree;
    my_second_int_tree = my_int_tree;
    my_second_int_tree.insert_node(11);
    cout << "Printing modified cloned tree\n";
    cout << my_second_int_tree;
    cout << "\n";
  }
  cout << "Cloned tree is destroyed but it doesn't affect the original tree\n";

  return 0;
}
