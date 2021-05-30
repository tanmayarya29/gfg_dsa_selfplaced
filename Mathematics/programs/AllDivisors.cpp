#include<iostream>
#include <algorithm>
#include<set>
using namespace std;

set<int> res;

//naive
void printDivisor(int n){//tc=theta n, auxsp=theta 1
    for(int i=1;i<=n;i++){
        if(n%i==0)cout<<i<<" ";
    }
}

//optimised but unordered
void printDivisorO(int n){//tc=theta sqrtn, auxsp=theta 1
    //other than 1 and itself
    for(int i=1;i*i<=n;i++){
        
        if(n%i==0){
            // cout<<i<<" ";
            res.insert(i);

        if(n/i!=i)
        {
            // cout<<n/i<<" ";
            res.insert(n/i);
            }
        
        }
    }
    for(auto x:res){
        cout<<x<<" ";
    }
}

//optimised and sorted
void printDivisorOp(int n){
    int i;
    for(i=1;i*i<n;i++){
        if(n%i==0)cout<<i<<" ";
    }
    for(;i>=1;i--){
        if(n%i==0)cout<<n/i<<" ";
    }
}

int main(){
    int n=100;
    // printDivisor(n);
    // printDivisorO(n);
    printDivisorOp(n);
}