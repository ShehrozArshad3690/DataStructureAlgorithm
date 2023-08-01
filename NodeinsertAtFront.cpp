#include <iostream>

using namespace std;

class Node
{
private:
    int data;   // holds data
    Node *next; // holds reference to the next node
public:
    Node(int data, Node *next) // constructor to initiallize node
    {
        this->data = data;
        this->next = next;
    }
    friend class List; // node class becomes public to list class
};
class List
{
private:
    Node *head; // holds reference to the first node of list

public:
    List() // default constructor
    {
        head = nullptr; // initially list is empty
    }
    bool isEmpty()
    {
        return !head; // means head is null(0) means false but to show it true to us we return it as !head
    }
    void insertAtFront(int data)
    {
        Node *newNode = new Node(data, nullptr);
        if (head == nullptr) // if list is empty
        {
            head = newNode; // make newNode as head
        }
        else
        {
            newNode->next = head; // connect the next part of newNode(address part) to the head(first node) of list
            head = newNode;
        }
    }
};

int main()
{
    List l1;
    cout << l1.isEmpty() << endl; // initially it will be empty so result will be true
    l1.insertAtFront(4);
    cout << l1.isEmpty() << endl;
}
