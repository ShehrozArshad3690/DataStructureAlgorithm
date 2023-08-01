#include <iostream>

using namespace std;

int binary(int arr[], int low, int high, int key)
{
    if (low>high)       //base case for unsuccessful search when key is not found
    {
        return -1;
    }
    int mid = low+(high -low) / 2;

    if (arr[mid] == key)        //base case for successful search when key is found
        return mid;

    else if (arr[mid] <= key)   //recursive case for upper half -> from mid to rightward
        binary(arr,mid+1,high,key);

    else
        binary(arr,low,mid-1,key);      //recursive case for lower half ->from mid to the leftward
}
int main()
{
    int li[] = {1, 2, 3, 4, 5, 6, 8, 9, 22, 78};
    cout << "the key is on index no:" << binary(li, 0, 9, 99);
}
