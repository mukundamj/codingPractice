#include <iostream>
#include "BinarySearchTree.h"

int main(int argc, const char* argv[])
{
    TreeUtils::TreeNode<int>* root = TreeUtils::bstInsert<int>(nullptr, 10);
    TreeUtils::bstInsert(root, 5);
    TreeUtils::bstInsert(root, 12);
    TreeUtils::bstInsert(root, 2);
    TreeUtils::bstInsert(root, 14);
    TreeUtils::bstInsert(root, 7);
    TreeUtils::bstInsert(root, 6);
    TreeUtils::bstInsert(root, 8);

    std::cout << "Preorer traversal" << std::endl;
    TreeUtils::preOrderTraversal(root);

    std::cout << "Inorder traversal" << std::endl;
    TreeUtils::inOrderTraversal(root);

    std::cout << "Postorder traversal" << std::endl;
    TreeUtils::postOrderTraversal(root);
 
    std::cout << "Iterative serach: does the tree have value 8: " << std::string(TreeUtils::bstSearchIterative(root, 8) ? "yes" : "no") << std::endl;
    std::cout << "Recursive serach: does the tree have value 8: " << std::string(TreeUtils::bstSearchRecursive(root, 8) ? "yes" : "no") << std::endl;

    std::cout << "Iterative serach: does the tree have value 10: " << std::string(TreeUtils::bstSearchIterative(root, 10) ? "yes" : "no") << std::endl;
    std::cout << "Recursive serach: does the tree have value 10: " << std::string(TreeUtils::bstSearchRecursive(root, 10) ? "yes" : "no") << std::endl;

    std::cout << "Iterative serach: does the tree have value 14: " << std::string(TreeUtils::bstSearchIterative(root, 14) ? "yes" : "no") << std::endl;
    std::cout << "Recursive serach: does the tree have value 14: " << std::string(TreeUtils::bstSearchRecursive(root, 14) ? "yes" : "no") << std::endl;

    std::cout << "Iterative serach: does the tree have value 20: " << std::string(TreeUtils::bstSearchIterative(root, 20) ? "yes" : "no") << std::endl;
    std::cout << "Recursive serach: does the tree have value 20: " << std::string(TreeUtils::bstSearchRecursive(root, 20) ? "yes" : "no") << std::endl;

    std::cout << "The minimum value in the tree is: " << (TreeUtils::bstMinimum(root))->val << std::endl;
    std::cout << "The maximum value in the tree is: " << (TreeUtils::bstMaximum(root))->val << std::endl;

    TreeUtils::destroyRecursively(root);
    return 0;
}

