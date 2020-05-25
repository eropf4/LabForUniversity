#include "TreeNode.h"

TreeNode::~TreeNode()
{
    delete left;
    delete right;
}