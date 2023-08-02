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
    friend class Queue;
};
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }
    bool isempty()
    {
        return !front && !rear;
    }
    void push(int data)
    {
        Node *newNode = new Node(data, nullptr);
        if (front == nullptr && rear == nullptr)
        {
            rear = newNode;
            front = newNode;
        }
        else
        {
            while (rear->next != nullptr)
            {
                rear = rear->next;
            }
            rear->next = newNode;
            rear = newNode;
        }
    }
    void pop()
    {
        if (front == nullptr && rear == nullptr)
        {
            cout << "Queue is empTy";
        }
        else
        {
            Node *curNode = front;
            front = front->next;
            delete curNode;
        }
    }
    void show()
    {
        if (front && rear == nullptr)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            Node *curNode = front;
            while (curNode->next != nullptr)
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
    Queue q1;
    cout << q1.isempty() << endl;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    cout << q1.isempty() << endl;
    q1.show();
    q1.pop();
    q1.show();
}