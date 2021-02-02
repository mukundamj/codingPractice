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
    Tree() : root(0) {}

    /*Time complexity T(n) = O(n), where n is number of nodes in the tree*/
    void PreOrderTraversal(TreeNode<T>* root) const;

    /*If the tree is a binary search tree then inorder tree traversal allows us to print
    the keys in a sorted order.
    Time complexity T(n) = O(n), where n is number of nodes in the tree*/
    void InOrderTraversal(TreeNode<T>* root) const;

    /*Time complexity T(n) = O(n), where n is number of nodes in the tree*/
    void PostOrderTraversal(TreeNode<T>* root) const;

    void Clone(const TreeNode<T>* root) const;

private:
    TreeNode<T>* root;
};

/*The keys in a binary search tree are always stored in such a way as to satisfy the
binary-search-tree property: left-node-key ≤ parent-node-key ≤ right-node-key 
*/
template<typename T = int>
class BinarySearchTree : public Tree
{
public:
    void Insert(TreeNode<T>* root, T val);
    TreeNode<T>* SearchRecursive(TreeNode<T>* root, T val);
    TreeNode<T>* SearchIterative(TreeNode<T>* root, T val);
};
