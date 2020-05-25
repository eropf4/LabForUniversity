#pragma once
class TreeNode
{
public:
    TreeNode() = default;
    TreeNode(const int val) : value(val) {}
    ~TreeNode();

    void SetLeftNode(TreeNode* node) { left = node; };
    TreeNode* GetLeftNode() const { return left; };

    void SetRightNode(TreeNode* node) { right = node; };
    TreeNode* GetRightNode() const { return right; };

    int GetValue() const { return value; };

private:
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    const int value = 0;
};