#include<iostream>

using namespace std;

int search(int list[],int size,int key)
{
    for (int i = 0; i < size; i++)
    {
        if (list[i]==key)
            return i;
    }
    
}
int main()
{
     int li[]={1,4,6,8,33,77,3,6};
     int siz=sizeof(li)/sizeof(li[0]);
     cout<<search(li,siz,33);
}
