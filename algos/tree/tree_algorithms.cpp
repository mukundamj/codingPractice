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
    void print_tree(const tree_node<T> *root);
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
    void print_tree() { print_tree(m_root); }
    //TODO: delete_node(T val);
    //TODO: create_tree(vector<T> nums);
};

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
void BST<T>::print_tree(const tree_node<T> *root)
{
  if (!root) return;
  print_tree(root->left);
  cout << root->val << " ";
  print_tree(root->right);
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
  cout << "\n";

  if (my_int_tree.search_node(10))
    cout << "10 is found in the tree\n";
  else 
    cout << "10 is not found in the tree\n";

  if (my_int_tree.search_node(-1))
    cout << "-1 is found in the tree\n";
  else 
    cout << "-1 is not found in the tree\n";

  return 0;
}
