#include <iostream>

using namespace std;

int main()
{
    int m,i;
    cout << "Enter length of array:";
    cin >> m;
    int n[m];
    for (i = 0; i < m; i++)
    {
        cout << "Enter "<<i+1<<" number to store:";
        cin >> n[i];
    }
    cout<<"Your array is:";
    for ( i = 0; i < m; i++)
    {
        cout<<n[i]<<" ";
    }
    

    return 0;
}
