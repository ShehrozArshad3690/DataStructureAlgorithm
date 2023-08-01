#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q1;
    cout<<q1.size()<<endl;      //0 because queue has no elements initially
    cout<<q1.empty()<<endl;     //1 means true -> as it is emty right now
    q1.push(8);                 //add element at rear or back
    q1.push(66);
    q1.push(17);
    cout<<q1.front()<<endl;     //it shows the element that is at the front or first of queue that is 8
    cout<<q1.back()<<endl;      //it shows the element that is at the back or last of queue that is 17
    q1.pop();                   //it removes the element from the front 
    cout<<q1.front()<<endl;
    cout<<q1.size()<<endl;      //2 as two elements are present in queue right now
    cout<<q1.empty()<<endl;     //0 means false -> as it is not empty right now
}
