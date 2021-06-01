#include <iostream>
using  namespace std;
bool chkSetBit(int n,int k){//using left shift
    if((n&(1<<(k-1)))!=0)return true;//101 & (001<<1) !=0
    else return false;
}
bool chkSetBit2(int n,int k){//using left shift
    if((n>>(k-1)&1)==1)return true;//101 & (001<<1) !=0
    else return false;
}

int main(){
    int n=5,k=3;//101
    cout<<chkSetBit(n,k)<<endl;
    cout<<chkSetBit2(n,k)<<endl;
}