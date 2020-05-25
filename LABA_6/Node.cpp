#include "Node.h"

Node::Node(int val)
{
    value = val;
}

Node::~Node()
{
    delete next;
}

Node* Node::getNext() const
{
    return next;
}

int Node::getValue() const
{
    return value;
}

void Node::push(Node* node)
{
    Node* tmpNext = this;
    while (tmpNext->next != nullptr)
        tmpNext = tmpNext->next;
    tmpNext->next = node;
}

void Node::deleteNext()
{
    if (next == nullptr)
        return;
    Node* tmp = next->getNext();
    next->next = nullptr;
    delete next;
    next = tmp;
}

