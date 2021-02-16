#include <iostream>
#include "BinarySearchTree.h"

int main(int argc, const char* argv[])
{
    BinarySearchTree<int> bst;
    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(12);
    bst.Insert(2);
    bst.Insert(14);
    bst.Insert(7);
    bst.Insert(6);
    bst.Insert(8);

    std::cout << "Preorer traversal" << std::endl;
    bst.PreOrderTraversal();

    std::cout << "Inorder traversal" << std::endl;
    bst.InOrderTraversal();

    std::cout << "Postorder traversal" << std::endl;
    bst.PostOrderTraversal();
 
    std::cout << "Iterative serach: does the tree have value 8: " << std::string(bst.SearchIterative(8) ? "yes" : "no") << std::endl;
    std::cout << "Recursive serach: does the tree have value 8: " << std::string(bst.SearchRecursive(8) ? "yes" : "no") << std::endl;

    std::cout << "Iterative serach: does the tree have value 10: " << std::string(bst.SearchIterative(10) ? "yes" : "no") << std::endl;
    std::cout << "Recursive serach: does the tree have value 10: " << std::string(bst.SearchRecursive(10) ? "yes" : "no") << std::endl;

    std::cout << "Iterative serach: does the tree have value 14: " << std::string(bst.SearchIterative(14) ? "yes" : "no") << std::endl;
    std::cout << "Recursive serach: does the tree have value 14: " << std::string(bst.SearchRecursive(14) ? "yes" : "no") << std::endl;

    std::cout << "Iterative serach: does the tree have value 20: " << std::string(bst.SearchIterative(20) ? "yes" : "no") << std::endl;
    std::cout << "Recursive serach: does the tree have value 20: " << std::string(bst.SearchRecursive(20) ? "yes" : "no") << std::endl;

    std::cout << "The minimum value in the tree is: " << bst.Minimum()->val << std::endl;
    std::cout << "The maximum value in the tree is: " << bst.Maximum()->val << std::endl;

    return 0;
}

