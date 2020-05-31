#include <iostream>
#include "TreeNode.h"
#include "BinaryTree.h"
#include <algorithm> 

using std::cin;
using std::cout;
using std::endl;

const int count = 3;
void printTree(TreeNode* root, int space)
{
    if (root == NULL)
        return;

    space += count;
    printTree(root->GetRightNode(), space);

    cout << endl;
    for (int i = count; i < space; i++)
        cout << " ";
    cout << root->GetValue() << "\n";

    printTree(root->GetLeftNode(), space);
}


TreeNode* CreateMinimalBST(const int* arr, const int begin, const int end)
{
    if (end < begin)
        return nullptr;

    const int mid = (begin + end) / 2;
    auto tree = new TreeNode(arr[mid]);

    tree->SetLeftNode(CreateMinimalBST(arr, begin, mid - 1));
    tree->SetRightNode(CreateMinimalBST(arr, mid + 1, end));

    return tree;
}



int main()
{
    BinaryTree tree;

    tree.Insert(6);
    tree.Insert(5);
    tree.Insert(4);
    tree.Insert(3);
    tree.Insert(2);
    tree.Insert(1);

    if (tree.Search(12))
        cout << tree.Search(12)->GetValue() << endl;
    else
        cout << "not contain" << endl;

    int arr[] = { 4, 3, 1, 12, 5, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::sort(arr, arr + n);

    BinaryTree minimalTree;
    minimalTree.SetRoot(CreateMinimalBST(arr, 0, n - 1));
    printTree(minimalTree.GetRoot(), 0);

    return 0;
}
