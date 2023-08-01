#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    cout<<s.size()<<endl;   //0 because stack is initially empty
    cout<<s.empty()<<endl;  //1 means true -> stack is empty yet
    s.push(8);
    s.push(5);
    cout<<s.size()<<endl;   //2 means two elements are there in stack now which is previously pushed
    cout<<s.empty()<<endl;  //0 means false -> stack is not empty now
    cout<<s.top()<<endl;    //5 -> as it is on the top right now
    s.pop();                //it removes 5 as it is on the top
    cout<<s.top();          //8 as it is now on the top of stack
}
