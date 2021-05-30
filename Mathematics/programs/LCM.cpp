#include<iostream>
using namespace std;

int gcdREC(int a,int b){
    if(b%a==0)return a;
    return gcdREC(b%a,a);
}

int LCM(int a, int b){
//lcm*hcf=a*b
//lcm=a*b/hcf
return a*b/gcdREC(a,b);
}

int main(){
    int a=12,b=15;
    cout<<LCM(a,b)<<endl;
}