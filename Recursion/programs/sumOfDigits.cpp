#include<iostream>
using namespace std;

int sod(int n){//time - theta(no of digit) sp thet(nod-1)
    if(n<=9)return 0;
    return n%10+sod(n/10);
}

int main(){
    int n=9987;
    cout<<sod(n);
}