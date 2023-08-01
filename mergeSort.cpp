#include<iostream>

using namespace std;
int merge(int ar[],int left,int mid,int right)
{
    int n1=mid-left+1;          //size of left sub array
    int n2=right-mid;           //size of right sub array
    //create temporary arrays
    int* L=new int[n1];
    int* R=new int[n2];
    //copy data to temporary arrays Left and Right
    for (int i = 0; i < n1; i++)
    {
        L[i]=ar[left+i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i]=ar[mid+1+i];
    }
    //merge the temporary arrays back into original array ar[] from left till right
    int i=0,j=0,k=left;     //initial index of merged subarray
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            ar[k]=L[i];
            i++;
        }
        else
        {
            ar[k]=R[j];
            j++;
        }
        k++;
    }
    //copy the remaining elements of left array, if there are any
    while(i<n1)
    {
        ar[k]=L[i];
        i++;
        k++;
    }
    //copy the remaining elements of right array, if there are any
    while(j<n2)
    {
        ar[k]=R[j];
        j++;
        k++;
    }
    //delete the temporary arrays to free up space
    delete[]L;
    delete[]R;
    
}
int mergsort(int ar[],int left, int right)
{
    if(left<right)
    {
        int mid=left+(right-left)/2;
        mergsort(ar,left,mid);          //left half
        mergsort(ar,mid+1,right);       //right half

        merge(ar,left,mid,right);
    }

}

int main()
{
     int ar[]={38,27,43,3,9,55,12,82,10,5};
     mergsort(ar,0,9);
     for (int i = 0; i < 10; i++)
     {
        cout<<ar[i]<<" ";
     }
     
}
