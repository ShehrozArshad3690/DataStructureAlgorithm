#include <iostream>

using namespace std;

void print(int arr[], int n)
{
    if (n == 0)             //base case means there is no element left in array
    {
        return;
    }
    cout<<arr[0];           //print first element of array
    print(arr+1,n-1);       //arr + 1 does not mean arr[1] rather it means pointer arethimetic expression ,When you add an integer value to a pointer, it moves the pointer to the next memory location based on the size of the data type it points to and arr + 1 points to the second element of the array 
}
int main()
{
    int ar[] = {1, 2, 3, 4, 5};
    int size = sizeof(ar)/sizeof(ar[0]);        // to calculate the number of elements in an array = sizeof(ar)-> total bytes of an array divided by sizeof(ar[0]) number of bytes occupied by one element
    print(ar,size);
}
