#include <iostream>
#include "Matrix3x3.h"
#include "MatrixXnX.h"
#include <time.h>
#include <vector>
#include "Node.h"
#include <cassert>

using namespace std;

void FirstTask();
void SecondTask();

void FirstTask() // 3x3 matrix static memory
{
    Matrix3x3 matrix;
    matrix.fillRandomElements(-10, 10);//create matrix

    for (auto i = 0; i < matrix.getDimension(); i++) // Print matrix
    {
        for (auto j = 0; j < matrix.getDimension(); j++)
            cout << matrix.element(i, j) << " ";
        cout << endl;
    }

    cout <<
        "Diagonal sum:" << endl <<
        "Principal\t" << matrix.sumPrincipalDiag() << "\tSecondary\t" << matrix.sumSecondaryDiag() << endl <<
        "Diag product:" << endl <<
        "Principal\t" << matrix.productPrincipalDiag() << "\tSecondary\t" << matrix.productSecondaryDiag() << endl <<
        "String sum:" << endl;
    for (auto i = 0; i < matrix.getDimension(); i++)
        cout << i << ":\t" << matrix.sumRow(i) << endl;
    cout << "Column max:" << endl;
    for (auto j = 0; j < matrix.getDimension(); j++)
        cout << j << ":\t" << matrix.maxColumn(j) << endl;
    cout << "Column min:" << endl;
    for (auto j = 0; j < matrix.getDimension(); j++)
        cout << j << ":\t" << matrix.minColumn(j) << endl;
    cout << "________________________" << endl;
}

void SecondTask() // NxN matrix dynamic memory
{
    MatrixXnX matrix = MatrixXnX(4);

    matrix.fillRandomElements(-10, 10);//create matrix

    for (auto i = 0; i < matrix.getDimension(); i++) // Print matrix
    {
        for (auto j = 0; j < matrix.getDimension(); j++)
            cout << matrix.element(i, j) << " ";
        cout << endl;
    }

    cout <<
        "Diagonal sum:" << endl <<
        "Principal\t" << matrix.sumPrincipalDiag() << "\tSecondary\t" << matrix.sumSecondaryDiag() << endl <<
        "Diag product:" << endl <<
        "Principal\t" << matrix.productPrincipalDiag() << "\tSecondary\t" << matrix.productSecondaryDiag() << endl <<
        "String sum:" << endl;
    for (auto i = 0; i < matrix.getDimension(); i++)
        cout << i << ":\t" << matrix.sumRow(i) << endl;
    cout << "Column max:" << endl;
    for (auto j = 0; j < matrix.getDimension(); j++)
        cout << j << ":\t" << matrix.maxColumn(j) << endl;
    cout << "Column min:" << endl;
    for (auto j = 0; j < matrix.getDimension(); j++)
        cout << j << ":\t" << matrix.minColumn(j) << endl;
    cout << "________________________" << endl;
}

void DeleteDuplicates(Node& head) 
{
    vector<int> items;
    Node* cursor = &head;
    items.push_back(cursor->getValue());
    while (cursor->getNext())
    {
        if (find(items.begin(), items.end(), cursor->getNext()->getValue()) != items.end())
        {
            cursor->deleteNext();
            continue;
        }
        items.push_back(cursor->getNext()->getValue());
        cursor = cursor->getNext();
    }
}

void FindKElementFromEnd(Node& list, int k)
{
    int count = 0;
    Node* head = &list;
    while (head != nullptr)  //find size of list
    {
        count++;
        head = head->getNext();
    }
    assert(k < count);
    head = &list;
    for (auto i = 0; i < count - k; i++)
        head = head->getNext();
    cout << head->getValue() << endl;
}


void PrintList(Node& node)
{
    Node* tmpNode = &node;
    while (tmpNode != NULL)
    {
        cout << tmpNode->getValue() << " ";
        tmpNode = tmpNode->getNext();
    }
    cout << endl;
}

int main()
{
    FirstTask();
    SecondTask();

    Node startNode = Node(5);
    startNode.push(new Node(3));
    startNode.push(new Node(2));
    startNode.push(new Node(1));
    startNode.push(new Node(3));
    startNode.push(new Node(1));
    startNode.push(new Node(3));
    startNode.push(new Node(4));
    startNode.push(new Node(2));

    PrintList(startNode);
    DeleteDuplicates(startNode);
    PrintList(startNode);
    FindKElementFromEnd(startNode, 3);
    return 0;
}