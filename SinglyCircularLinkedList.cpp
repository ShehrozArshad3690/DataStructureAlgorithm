#include <iostream>

using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
    friend class SinglyCircularLinkedList;
};
class SinglyCircularLinkedList
{
private:
    Node *head;

public:
    SinglyCircularLinkedList()
    {
        head = nullptr;
    }
    bool isEmpty()
    {
        return !head;
    }
    void insertAtFront(int data)
    {
        Node *newNode = new Node(data, nullptr);
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node *curNode=head;
            while (curNode->next!=head)
            {
                curNode=curNode->next;
            }
            curNode->next=nullptr;
            newNode->next=head;
            head=newNode;
            Node *temp=head;
            while (temp->next!=nullptr)
            {
                temp=temp->next;
            }
            temp->next=head;
        }
    }
    void show()
    {
        if (head == nullptr)
        {
            cout << "List is empty";
        }
        else
        {
            Node *curNode = head;
            while (curNode->next != head)
            {
                cout << curNode->data << " ";
                curNode = curNode->next;
            }
            cout << curNode->data << endl;
        }
    }
};

int main()
{
    SinglyCircularLinkedList S1;
    S1.insertAtFront(9);
    S1.insertAtFront(6);
    S1.insertAtFront(7);
    S1.insertAtFront(10);
    S1.show();
}
