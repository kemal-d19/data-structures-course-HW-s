// BinaryTreeNode.h
// DO NOT MODIFY THIS FILE
// YOU DON’T NEED TO IMPLEMENT THIS FILE
// YOU WILL NOT SUBMIT THIS FILE

#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>

using namespace std;

class BinaryTreeNode {
private:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

public:
    BinaryTreeNode(int data, BinaryTreeNode* left, BinaryTreeNode* right);
    ~BinaryTreeNode();
    int get_data() const;
    void set_data(int value);
    BinaryTreeNode* get_left() const;
    void set_left(BinaryTreeNode* node);
    BinaryTreeNode* get_right() const;
    void set_right(BinaryTreeNode* node);

    /*
    The print_unique function performs a level-order traversal of a binary tree
    and prints its structure without enforcing the complete binary tree format
    (i.e., it doesn’t pad missing nodes to ensure 2^(n-1) entries at each level).
    Instead, it only includes null where a child is missing for an existing parent node,
    stopping the traversal when all actual nodes (and their explicit null placeholders)
    have been processed.
    Nodes are printed level by level.
    If a node is missing (a nullptr child of an existing node), "null" is printed.
    The function stops when all nodes and their placeholders have been processed,
    without artificially adding more null nodes to match the size of a complete
    binary tree at deeper levels.
    Consider this binary tree:
          1
         / \
        2   3
       /
      4
    Printed output will be:
    1
    2 3
    4 null null null
    null null
    */
    void print_unique();
};

#endif // BINARY_TREE_NODE_H
