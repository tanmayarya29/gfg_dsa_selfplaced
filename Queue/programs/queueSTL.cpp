#include <iostream>
#include <queue>
using namespace std;
//it can be implemented using list and deque but not vector as it not support pop front//deque is preferred 
int main() 
{ 
    queue <int> q; 
    q.push(10); 
    q.push(20); 
    q.push(30); 
  cout<<q.size()<<endl;

   while(q.empty() == false)
   {
       cout << q.front() << " " << q.back() << endl;
       q.pop();
   }
    
  
    return 0; 
} 