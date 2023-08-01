#include<iostream>

using namespace std;

int merge(int res[],int a1[],int a2[])
{    
    int i=0,j=0,k=0;
    while(i<7 && j<9)
    {
        if(a1[i]<=a2[j])
        {
            res[k]=a1[i];
            i++;
        }
        else{
            res[k]=a2[j];
            j++;
        }
        k++;
    }
    while (i<7)
    {
        res[k]=a1[i];
        i++;
        k++;
    }
    while (j<9)
    {
        res[k]=a2[j];
        j++;
        k++;
    } 
}
int main()
{
    int ar1[]={12,23,34,45,56,67,78};
    int ar2[]={11,22,33,54,76,79,80,87,90};
    int* result=new int[16];
    merge(result,ar1,ar2);
    for (int i = 0; i < 16; i++)
    {
        cout<<result[i]<<" ";
    }
    
}
