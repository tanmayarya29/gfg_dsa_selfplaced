#include <iostream>
#include <stack>
using namespace std;
//it can be implemented using list, vector, deque(back,size,empty,push_back,pop_back)
//by default it is implemented using deque 
//container adapter 
//The C++ Standard Library implements class templates such as stack, queue, and priority_queue 
//as a container that puts constraints on the process of storage and retrieval of elements
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.push(5);
    cout<<s.top()<<endl;
    
    while(s.empty()==false){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0; 
}
