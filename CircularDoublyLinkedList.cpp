#include <iostream>

using namespace std;

class Node
{
private:
    int data;
    Node *pre;
    Node *next;

public:
    Node(int data, Node *pre, Node *next)
    {
        this->data = data;
        this->pre = pre;
        this->next = next;
    }
    friend class CircularDoublyLinkedList;
};
class CircularDoublyLinkedList
{
private:
    Node *head;

public:
    CircularDoublyLinkedList()
    {
        head = nullptr;
    }
    bool isempty()
    {
        return !head;
    }
    void insertAtend(int data)
    {
        Node* newNode=new Node(data,nullptr,nullptr);
        if (head==nullptr)
        {
            head=newNode;
            newNode->next=head;
            head->pre=newNode;
        }
        else
        {
            Node *curNode=head;
            while (curNode->next!=head)
            {
                curNode=curNode->next;
            }
            curNode->next=newNode;
            newNode->pre=curNode;
            newNode->next=head;
            head->pre=newNode;
        }
    }
    void show(){
        if (head==nullptr)
        {
            cout<<"List is empty";
        }
        else
        {
            Node* curNode=head;
            while (curNode->next!=head)
            {
                cout<<curNode->data<<" ";
                curNode=curNode->next;
            }
            cout<<curNode->data<<endl;
        }   
    }
};
int main()
{
    CircularDoublyLinkedList c1;
    c1.insertAtend(8);
    c1.insertAtend(9);
    c1.insertAtend(6);
    c1.insertAtend(23);
    c1.show();
}