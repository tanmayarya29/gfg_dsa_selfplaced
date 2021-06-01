#include<iostream>
using namespace std;

bool isPowerOf2(int n){
    return (n!=0&&!(n&(n-1)));
}
int main(){
    int n=1024;
    cout<<isPowerOf2(n)<<endl;
}