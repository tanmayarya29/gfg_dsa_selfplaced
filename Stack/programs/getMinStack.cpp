#include <bits/stdc++.h>
using namespace std;

struct MyStack {
 
    stack<int> ms;
    stack<int> as;
 
void push(int x) {
 
      if(ms.empty() ) {
          ms.push(x);as.push(x);return;
      }
      
      ms.push(x);
      
      if(as.top()>=ms.top())
        as.push(x);
   }
 
void pop() {
 
    if(as.top()==ms.top())
        as.pop();
    ms.pop();
    
   }

int top() {
     return ms.top();
   }
 
int getMin() {
      return as.top();
   }
};

int main()
{
    MyStack s;
    s.push(4);
    s.push(5);
    s.push(8);
    s.push(1);
    s.pop();
 
    cout<<" Minimum Element from Stack: " <<s.getMin();
  
    return 0; 
}
