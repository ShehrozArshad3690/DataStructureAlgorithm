while (curNode->next!=nullptr)
            {
                cout<<curNode->data<<" ";
                curNode=curNode->next;
            }
            cout<<curNode->data<<endl;