#include <iostream>

using namespace std;

int binary(int arr[], int low, int high, int key)
{
    while (low <= high) {
 
        // Find index of middle element
        int mid = (low + high) / 2;
 
        // Check if key is present at mid
        if (arr[mid] == key)
            return mid;
 
        // If key greater, ignore left half
        if (arr[mid] <= key)
            low = mid + 1;
 
        // If key is smaller, ignore right half
        else
            high = mid - 1;
    }
 
    // If we reach here, then element was not present
    return -1;
}
int main()
{
    int li[] = {1, 2, 3, 4, 5, 6, 8, 9, 22, 78};
    cout << "the key is on index no:"<<binary(li,0,9, 4);
}
