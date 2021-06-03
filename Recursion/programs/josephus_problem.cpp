#include<iostream>
using namespace std;

int alive(int n,int k){//theta n time n space
    if(n==1)return 0;
    return (alive(n-1,k)+k)%n;
}
//if posn always begins from 1 add 1 to result
int main(){
    int n=7,k=3;
    cout<<alive(n,k);
}