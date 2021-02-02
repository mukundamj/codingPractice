#include "ArrayUtils.h"
#include "GraphUtils.h"
#include "BackTracking.h"
#include "TreeUtils.h"
#include "ListUtils.h"
#include "BackTracking.h"
#include <vector>
#include <string>
#include <iostream>
#include <bits/stdc++.h>

int
main(int argc, const char* argv[])
{
	//ArrayUtils test start                                                         
	std::vector<int> arrayOfNums1 = {1, 1, 1, 1};
	std::vector<int> arrayOfNums2 = {2};
	std::vector<int> arrayOfNums3 = {15, 0};
	std::vector<int> arrayOfNums4 = {0, 9};
	std::vector<int> arrayOfNums5 = {0, 35, 0};
	std::vector<int> arrayOfNums6 = {1, 2, 1};
	std::vector<int> arrayOfNums7 = {1, 2, 3, 2, 1};
	std::vector<int> arrayOfNums8 = {0, 5};

	std::cout << "For the array, " << ArrayUtils::Print(arrayOfNums1) << ", Expected peak = " << INT_MIN << ", Actual peak = "
		<< ArrayUtils::FindPeakElement(arrayOfNums1) << std::endl;

	std::cout << "For the array, " << ArrayUtils::Print(arrayOfNums2) << ", Expected peak = " << 2 << ", Actual peak = "
		<< ArrayUtils::FindPeakElement(arrayOfNums2) << std::endl;

	std::cout << "For the array, " << ArrayUtils::Print(arrayOfNums3) << ", Expected peak = " << 15 << ", Actual peak = "
		<< ArrayUtils::FindPeakElement(arrayOfNums3) << std::endl;

	std::cout << "For the array, " << ArrayUtils::Print(arrayOfNums4) << ", Expected peak = " << 9 << ", Actual peak = "
		<< ArrayUtils::FindPeakElement(arrayOfNums4) << std::endl;

	std::cout << "For the array, " << ArrayUtils::Print(arrayOfNums5) << ", Expected peak = " << 35 << ", Actual peak = "
		<< ArrayUtils::FindPeakElement(arrayOfNums5) << std::endl;

	std::cout << "For the array, " << ArrayUtils::Print(arrayOfNums6) << ", Expected peak = " << 2 << ", Actual peak = "
		<< ArrayUtils::FindPeakElement(arrayOfNums6) << std::endl;

	std::cout << "For the array, " << ArrayUtils::Print(arrayOfNums7) << ", Expected peak = " << 3 << ", Actual peak = "
		<< ArrayUtils::FindPeakElement(arrayOfNums7) << std::endl;

	std::cout << "For the array, " << ArrayUtils::Print(arrayOfNums8) << ", Expected peak = " << 5 << ", Actual peak = "
		<< ArrayUtils::FindPeakElement(arrayOfNums8) << std::endl;


	//GraphUtils test start
	std::vector<std::vector<int>> graph1 = 
	{
		{1, 2, 3},
		{0, 2},
		{1, 1, 3},
		{0, 2},
	};

	std::vector<std::vector<int>> graph2 = 
	{
		{1, 3},
		{0, 2},
		{1, 3},
		{0, 2},
	};

	std::cout << "Is graph1 bipartite: " << GraphUtils::IsBipartite(graph1) << std::endl;
	std::cout << "Is graph2 bipartite: " << GraphUtils::IsBipartite(graph2) << std::endl;

	/*
	//DoesWordExist(Using BackTracking approach) test start
	std::string word = "ABCCED";

	std::vector<std::vector<char>> board = {
		{'A','B','C','E'}, 
		{'S','F','C','S'}, 
		{'A','D','E','E'}, 
	};

	std::cout << ArrayUtils::Print(board);

	std::cout << "Does the word exist: " << BackTracking::DoesWordExist(board, word) << std::endl;
	*/

	//TreeUtils test start
	TreeNode<int> *r = new TreeNode<int>(1);
	r->left = new TreeNode<int>(2);
	r->right = new TreeNode<int>(3);
	r->left->left = new TreeNode<int>(4);
	r->left->right = new TreeNode<int>(5);
	r->right->left = new TreeNode<int>(6);
	r->right->right = new TreeNode<int>(7);
	r->right->right->left = new TreeNode<int>(8);
	r->right->right->right = new TreeNode<int>(9);

	const TreeNode<int>* clonedRoot = TreeUtils<int>::Clone(r);
	std::cout << "The original tree is (inorder): " << TreeUtils<int>::InOrderTraversalPrint(r) << std::endl;
	std::cout << "The original tree is (preorder): " << TreeUtils<int>::PreOrderTraversalPrint(r) << std::endl;
	std::cout << "The cloned tree is (inorder) " << TreeUtils<int>::InOrderTraversalPrint(clonedRoot) << std::endl;
	std::cout << "The cloned tree is (preorder) " << TreeUtils<int>::PreOrderTraversalPrint(clonedRoot) << std::endl;

	//ListUtils test start
	ListNode* head = ListUtils::GenerateRandomList(10);
	std::cout << "List before sorting is " << ListUtils::Print(head) << std::endl;
	std::cout << "List after sorting is " << ListUtils::Print(ListUtils::MergeSort(head)) << std::endl;

	head = ListUtils::GenerateRandomList(0);
	std::cout << "List before sorting is " << ListUtils::Print(head) << std::endl;
	std::cout << "List after sorting is " << ListUtils::Print(ListUtils::MergeSort(head)) << std::endl;

	head = ListUtils::GenerateRandomList(1);
	std::cout << "List before sorting is " << ListUtils::Print(head) << std::endl;
	std::cout << "List after sorting is " << ListUtils::Print(ListUtils::MergeSort(head)) << std::endl;

	head = ListUtils::GenerateRandomList(101);
	std::cout << "List before sorting is " << ListUtils::Print(head) << std::endl;
	std::cout << "List after sorting is " << ListUtils::Print(ListUtils::MergeSort(head)) << std::endl;

	return 0;
}

