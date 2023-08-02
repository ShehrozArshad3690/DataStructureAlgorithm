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
    friend class stack;
};
class stack
{
private:
    Node *top;

public:
    stack()
    {
        top = nullptr;
    }
    bool isempty()
    {
        return !top;
    }
    void push(int data)
    {
        Node* newNode=new Node(data,nullptr);
        if (top==nullptr)
        {
            top=newNode;
        }
        else
        {
            newNode->next=top;
            top=newNode;
        }
    }
    void show()
    {
        if (top==nullptr)
        {
            cout<<"Stack is empTy"<<endl;
        }
        else
        {
            Node* curNode=top;
            while (curNode->next!=nullptr)
            {
                cout<<curNode->data<<" ";
                curNode=curNode->next;
            }
            cout<<curNode->data<<endl;
        }  
    }
    void pop()
    {
        if (top==nullptr)
        {
            cout<<"Stack is Empty";
        }
        else
        {
            Node* curNode=top->next;
            delete top;
            top=curNode;
        }
        
    }
};
int main()
{
    stack s1;
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);
    s1.show();
    s1.pop();
    s1.pop();
    s1.show();
}