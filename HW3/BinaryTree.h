#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BinaryTreeNode.h"
#include <stack>
#include <queue>
#include <vector>
#include <algorithm> // You can use sort, max, min

class BinaryTree {
private:
    BinaryTreeNode *root;
public:
    BinaryTree(BinaryTreeNode *root);   // Constructor to initialize the tree
    ~BinaryTree();  // Destructor to deallocate memory
    
    BinaryTreeNode* get_root();

    bool isBST();           // Check if the tree is a Binary Search Tree
    bool isFull();          // Check if the tree is a full binary tree
    bool isBalanced();      // Check if the tree is balanced
    bool isChain();         // Check if the tree is a chain
    bool contains(int number);   // Check if the tree contains the number
    int findSmallestMissingPositive();   // Find the smallest missing positive integer in the tree
    int countOddNumbers();  // Count the number of odd numbers in the tree
    /*
    Convert the tree to a complete binary search tree, don't modify the original tree, create and return a new BinaryTree
    */
    BinaryTree* convertToCompleteBST();  
    bool isComplete();  // Check if the tree is complete
    int isHeap();       // Check if the tree is a heap (1: max-heap, 2: min-heap, 0: not a heap)
    
    // DEFINE HELPER FUNCTIONS HERE IF NEEDED
    BinaryTreeNode* build_BST( vector<int>* array, int start, int end);
    bool is_com_full(int num);
    void inorder(BinaryTreeNode* p, vector<int>* array);
    bool is_contains(BinaryTreeNode* p, int value);
    bool is_Balanced(BinaryTreeNode* p);
    int height(BinaryTreeNode* p);
    bool is_maxHeap(BinaryTreeNode* p);
    bool is_minHeap(BinaryTreeNode* p);
    bool is_BST(BinaryTreeNode* p, int min_val, int max_val);
    bool is_Full(BinaryTreeNode* p);
    void removeAll(BinaryTreeNode* p);
};

#endif // BINARYTREE_H