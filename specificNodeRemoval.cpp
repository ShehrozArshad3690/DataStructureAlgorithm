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
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data, nullptr);
        if (head == nullptr) // if list is empty
        {
            head = newNode; // make newNode as head
        }
        else
        {
            Node *curNode = head;            // copy head in curNode pointer
            while (curNode->next != nullptr) // find the node having null value in next
            {
                curNode = curNode->next;
            }
            curNode->next = newNode; // connecting next part of last node(address part) to the newNode
        }
    }
    void RemoveLast()
    {
        if (head==nullptr)
        {
            cout<<"List is empty"<<endl;
        }
        else if(head->next==nullptr)
        {
            delete head;
            head=nullptr;
        }
        else
        {
            Node *preNode=head;
            Node *curNode=head->next;
            while (curNode->next!=nullptr)
            {
                preNode=curNode;
                curNode=curNode->next;
            }
            delete curNode;
            preNode->next=nullptr;
        }
    }
    void RemoveFirst()
    {
        if (head==nullptr)
        {
            cout<<"List is empTy"<<endl;
        }
        else if (head->next==nullptr)
        {
            delete head;
            head=nullptr;
        }
        else
        {
            Node *curNode=head->next;
            delete head;
            head=curNode;
        }   
    }
    void removeSpecificNode(int sp)
    {
        Node *preNode=head;
        Node *curNode=head->next;
        Node *nexNode=curNode->next;
        while (curNode->next!=nullptr && curNode->data!=sp)
        {
            preNode=curNode;
            curNode=nexNode;
            nexNode=nexNode->next;
        }
        delete curNode;
        preNode->next=nexNode;
    }
    void show()
    {
        if (head == nullptr)
        {
            cout << "List is Empty" << endl;
        }
        else
        {
            Node *curNode = head;
            while (curNode->next != nullptr)
            {
                cout << curNode->data << " ";
                curNode = curNode->next;
            }
            cout << curNode->data<<endl;
        }
    }
};

int main()
{
    List l1;
    cout << l1.isEmpty() << endl; // initially it will be empty so result will be true
    l1.show();
    l1.insertAtFront(2);
    l1.insertAtEnd(3);
    l1.insertAtFront(6);
    l1.insertAtEnd(7);
    l1.insertAtFront(9);
    l1.insertAtEnd(1);
    cout << l1.isEmpty() << endl;
    l1.show();
    l1.RemoveLast();
    l1.RemoveLast();
    l1.show();
    l1.RemoveFirst();
    l1.show();
    l1.insertAtEnd(77);
    l1.insertAtEnd(23);
    l1.show();
    l1.removeSpecificNode(77);
    l1.show();
}
