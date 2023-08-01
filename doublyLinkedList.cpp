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
    friend class doublyLinkedList;
};
class doublyLinkedList
{
private:
    Node *head;

public:
    doublyLinkedList()
    {
        head = nullptr;
    }
    bool isempty()
    {
        return !head;
    }
    void insertAtend(int data)
    {
        Node *newNode=new Node(data,nullptr,nullptr);
        if (head==nullptr)
        {
            head=newNode;
        }
        else
        {
            Node *curNode=head;
            while (curNode->next!=nullptr)
            {
                curNode=curNode->next;
            }
            curNode->next=newNode;
            newNode->pre=curNode;
        }
    }
    void show(){
        if (head==nullptr)
        {
            cout<<"List is Empty";
        }
        else
        {
            Node* curNode=head;
            while (curNode->next!=nullptr)
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
    doublyLinkedList d1;
    d1.insertAtend(9);
    d1.insertAtend(78);
    d1.insertAtend(67);
    d1.show();
}
