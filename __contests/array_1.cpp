#include<bits/stdc++.h>
using namespace std;
int steps=0;
int powerOf2(int n){
    return log2(n);
}

bool isPowerofTwo(long long n){
        
        // Your code here    
        return (n!=0&&!(n&(n-1)));
}

int soln(int n){

    if(n==1)return steps;//base case
    if (isPowerofTwo(n))return (powerOf2(n)+steps);

    if(n%2==0){
        steps++;
        soln(n/2);
    }else{
        steps++;
        soln(n-1);
    }

}

int main(){
    int t=1;
    cin>>t;
    while(t--)
    {
        steps=0;
        int n=5;
        cin>>n;
        // cout<<isPowerofTwo(n)<<"-"<<powerOf2(n)<<endl;
        cout<<soln(n)<<endl;
    }
}