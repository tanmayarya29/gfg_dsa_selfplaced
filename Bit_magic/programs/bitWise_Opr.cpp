#include <iostream>
using namespace std;
 int main(){
     //bitwise opr
     int a=3,b=6;//3=011,6-110
     cout<<(a&b)<<endl;//both 1
     cout<<(a|b)<<endl;//one 1
     cout<<(a^b)<<endl;//same 0 diff 1

     cout<<(a<<b)<<endl;// ==> a*2^b
     cout<<(a>>1)<<endl;// ==> floor(a/2^b)
     unsigned c=1;
     signed d=1;//2^n-x
     cout<<(~c)<<endl;

 }