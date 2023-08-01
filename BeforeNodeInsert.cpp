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
    void insertAfterNode(int pre,int data)
    {
        Node *newNode = new Node(data, nullptr);
        Node *curNode=head;
        Node *nexNode=head->next;
        while (curNode->next!=nullptr && curNode->data!=pre)
        {
            curNode=nexNode;
            nexNode=nexNode->next;
        }
        curNode->next=newNode;
        newNode->next=nexNode;
    }
    void insertBeforeNode(int nex,int data)
    {
        Node *newNode = new Node(data, nullptr);
        Node *curNode=head;
        Node *nexNode=head->next;
        while (curNode->next!=nullptr && nexNode->data!=nex)
        {
            curNode=nexNode;
            nexNode=nexNode->next;
        }
        curNode->next=newNode;
        newNode->next=nexNode;
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
            cout << curNode->data;
        }
    }
};

int main()
{
    List l1;
    l1.insertAtFront(2);
    l1.insertAtEnd(3);
    l1.insertAtFront(6);
    l1.insertAtEnd(7);
    l1.insertAtFront(9);
    l1.insertAtEnd(1);
    l1.show();
    cout<<endl;
    l1.insertAfterNode(6,5);
    l1.show();
    cout<<endl;
    l1.insertBeforeNode(1,8);
    l1.show();
}
