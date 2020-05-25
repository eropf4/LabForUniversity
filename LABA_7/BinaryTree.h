#pragma once

#include "TreeNode.h"

class BinaryTree
{
public:
    BinaryTree() = default;
    BinaryTree(const int value) : root(new TreeNode(value)) {}
    ~BinaryTree() { delete root; };

    void SetRoot(TreeNode* root_arg) { root = root_arg; };
    TreeNode* GetRoot() const { return root; };

    void Insert(int value) { Insert(root, value); };
    TreeNode* Search(const int value) const { return Search(root, value); };
private:
    TreeNode* root = nullptr;
    static TreeNode* Insert(TreeNode* const root, const int value);
    static TreeNode* Search(TreeNode* const root, const int value);
};