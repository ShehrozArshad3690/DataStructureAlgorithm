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
    void insertAtEnd(int data)
    {
        Node* newNode= new Node(data ,nullptr);
        if(head==nullptr)           //if list is empty
        {
            head=newNode;           //make newNode as head
        }
        else
        {
            Node* curNode=head;         //copy head in curNode pointer
            while (curNode->next!=nullptr)      //find the node having null value in next
            {
                curNode=curNode->next;
            }
            curNode->next=newNode;              //connecting next part of last node(address part) to the newNode
        }
    }

};

int main()
{
    List l1;
    cout<<l1.isEmpty()<<endl;       //initially it will be empty so result will be true
    l1.insertAtEnd(4);              //4 will be inserted at the head   ->       line 35 will be executed
    cout<<l1.isEmpty()<<endl;       //initiallize with element 4 
    l1.insertAtEnd(55);             //55 wiil be inserted at the end of node(head yet)     ->    line 46 will be executed
    l1.insertAtEnd(19);             //19 will be inserted after 55(end of node)     ->      line 42 will be executed untill a node with null next will be found
}
