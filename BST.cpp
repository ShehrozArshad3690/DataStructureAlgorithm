#include <iostream>

using namespace std;

class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
    friend class Tree;
};
class Tree
{
private:
    Node *root;

public:
    Tree()
    {
        root = nullptr;
    }
    bool isEmpty()
    {
        return !root;
    }
    void insertNode(int data)
    {
        Node *newNode = new Node(data, nullptr, nullptr);
        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            Node *curNode = root;
            while (curNode != nullptr)
            {
                if (data < curNode->data)
                {
                    if (curNode->left == nullptr)
                    {
                        curNode->left = newNode;
                        break;
                    }
                    curNode = curNode->left;
                }
                else
                {
                    if (curNode->right == nullptr)
                    {
                        curNode->right = newNode;
                        break;
                    }
                    curNode = curNode->right;
                }
            }
        }
    }
    void SearchNode(int data)
    {
        if (root == nullptr)
        {
            cout << "Tree is Empty" << endl;
        }
        else
        {
            Node *curNode = root;
            int count = 0;
            while (curNode!= nullptr)
            {
                if (data == curNode->data)
                {
                    cout << "Key found on level:" << count << endl;
                    return;
                }

                else if (data < curNode->data)
                {
                    curNode = curNode->left;
                }
                else
                {
                    curNode = curNode->right;
                }
                count++;
            }
            cout<<"Key not found in tree"<<endl;
        }
    }
};
int main()
{
    Tree t1;
    cout << t1.isEmpty() << endl;
    t1.insertNode(6);
    t1.insertNode(2);
    t1.insertNode(4);
    t1.insertNode(8);
    t1.insertNode(5);
    t1.insertNode(9);
    t1.insertNode(3);
    t1.insertNode(0);
    t1.insertNode(7);
    cout << t1.isEmpty() << endl;
    t1.SearchNode(22);
}
