#include <iostream>

using namespace std;

int search(int list[], int size, int key)
{
    if (size<0)        //when key element does not exist(base case) unsuccessfull
    {
        return -1;
    }
    else if(list[size]==key)        //when key is found and successful case(also another base case)
    {
        return size;
    }

    return search(list,size-1,key);     //recursive case
}
int main()
{
    int li[] = {1, 4, 6, 8, 33, 77, 3, 6};
    int siz = sizeof(li) / sizeof(li[0]);
    cout << search(li, siz, 33);
}
