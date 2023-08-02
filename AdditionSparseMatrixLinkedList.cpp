#include <iostream>

using namespace std;

class Node
{
private:
    int row;
    int column;
    int value;
    Node *next;

public:
    Node(int row, int column, int value, Node *next)
    {
        this->row = row;
        this->column = column;
        this->value = value;
        this->next = next;
    }
    friend class List;
};
class List
{
private:
    Node *head;

public:
    List()
    {
        head = nullptr;
    }
    bool isempty()
    {
        return !head;
    }
    void insert(int row, int column, int value)
    {
        Node *newNode = new Node(row, column, value, nullptr);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *curNode = head;
            while (curNode->next != nullptr)
            {
                curNode = curNode->next;
            }
            curNode->next = newNode;
        }
    }
    void show()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *curNode = head;
            while (curNode->next != nullptr)
            {
                cout << curNode->row << "," << curNode->column << "," << curNode->value<<"\t";
                curNode = curNode->next;
            }
            cout << curNode->row << "," << curNode->column << "," << curNode->value<<endl;
        }
    }
};

int main()
{
    List l1,l2;
    cout<<"1st Linked List"<<endl;
    l1.insert(4, 6, 3);
    l1.insert(0,0,6);
    l1.insert(1,2,3);
    l1.insert(3,2,9);
    l1.show();
    cout<<"2nd Linked List"<<endl;
    l2.insert(4,6,2);
    l2.insert(1,2,5);
    l2.insert(3,4,7);
    l2.show();
}
