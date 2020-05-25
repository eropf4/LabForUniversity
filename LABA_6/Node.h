#pragma once
#pragma once
class Node {
public:
    Node(int value);
    ~Node();
    Node* getNext() const;
    int getValue() const;
    void push(Node* node);
    void deleteNext();
private:
    int value;
    Node* next = nullptr;
};
