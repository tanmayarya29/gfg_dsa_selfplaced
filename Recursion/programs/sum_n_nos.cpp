#include<iostream>
using namespace std;
int sum(int n){//theta of n time n sp
    //w/o tail rec
    if (n==0)return 0;
    return n+sum(n-1);
}

int main(){
    int n=5;
    cout<<sum(n)<<endl;
}