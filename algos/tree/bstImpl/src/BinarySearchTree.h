#define pragma

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
