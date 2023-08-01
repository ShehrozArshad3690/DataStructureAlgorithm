#include <iostream>

using namespace std;

int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return x;
    }
    return x * power(x,n-1);
}
int main()
{
    int a, b;
    cout << "Enter number:";
    cin >> a;
    cout << "Enter power:";
    cin >> b;
    cout<<power(a,b);
}
