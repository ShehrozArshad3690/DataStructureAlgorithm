#include <iostream>

using namespace std;

double sum(double a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return 1 + a * sum(a, n - 1); // this will only return final result/element of stack after poping


    // #CODE 2-> this code prints all the intermediate results of stack from top to bottom
    //  double result= 1 + a * sum(a, n - 1);
    //  cout<<"Intermediate result:"<<result<<endl;
    //  return result;
}
int main()
{
    cout<<sum(4.56,7);
    // #CODE 2 -> cout<<"final result is:"<<sum(4.56,7);
}
