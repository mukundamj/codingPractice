#pragma once
#include <iostream>

using namespace std;

template<class T>
struct tree_node
{
  T val;
  tree_node *left;
  tree_node *right;
  tree_node(T x) : val{x}, left{NULL}, right{NULL} { }
};

template<class T>
class BST
{
  private:
    tree_node<T> *m_root;
    tree_node<T> *insert_node(tree_node<T> *root, const T val);
    const tree_node<T>* search_node(const tree_node<T> *root, const T val);
    void print_tree_helper(const tree_node<T> *root);
    void print_tree_overload(ostream &out, const tree_node<T> *root) const;
    void delete_tree(tree_node<T> *root);

  public:
    BST<T>() : m_root{NULL} { cout << "BST created\n"; }

    ~BST<T>()
    {
      delete_tree(m_root);
      cout << "BST deleted\n";
    }

    void insert_node(const T val)
    {
      if (m_root) insert_node(m_root, val);
      else m_root = new tree_node<T>(val);
    }

    const tree_node<T>* search_node(const T val) { return search_node(m_root, val); }

    void print_tree() { print_tree_helper(m_root); }

    //Don't want shallow copy hence not allowing copy constructor
    BST<T>(const BST<T>& bst) = delete;

    BST<T>& operator= (const BST<T>& bst);

    friend ostream& operator<< (ostream &out, const BST<T> &tree)
    {
      tree.print_tree_overload(out, tree.m_root);
      return out;
    }
   
    //TODO: delete_node(T val);
    //TODO: create_tree(vector<T> nums);
};

