#include <iostream>

using namespace std;

int partition(int A[], int left, int right)
{
    int l = left, r = right;
    int p = left; // choosing first element as pivot

    // partitioning based on pivot(p)
    while (l < r)
    {
        while (A[l] <= A[p] && l < r)       //movement of left pointer to right
        {
            l++;
        }
        while (A[r] > A[p])                 //movement of right pointer to left
        {
            r--;
        }
        if (l < r)                          
        {
            swap(A[l], A[r]);               //swapping of greater value from left with the smaller value to the right
        }
    }
    swap(A[r], A[p]);                       //swapping of pivot element with rifht element
    return r;
}
int quickSort(int A[], int left, int right)
{
    if (left < right)
    {
        int pi = partition(A, left, right); // find pivot point

        quickSort(A, left, pi - 1);  // left half array for smaller values from pivot
        quickSort(A, pi + 1, right); // right half array for greater values from pivot
    }
}
int main()
{
    int ar[] = {7, 4, 6, 9, 2, 8, 5, 1, 3};
    cout<<"UnSorted List"<<endl;
    for (int i = 0; i < 9; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    cout<<"Sorted List"<<endl;
    quickSort(ar, 0, 8);
    for (int i = 0; i < 9; i++)
    {
        cout << ar[i] << " ";
    }
}
