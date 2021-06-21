#include<bits/stdc++.h>
using namespace std;
vector<long long> PS;

void findPS(int arr[],int n){
    int sum=arr[0];
    PS.push_back(sum);
    for(int i=1;i<n;i++){
        sum+=arr[i];
        PS.push_back(sum);
    }
}

int getSum(int arr[],int n,int l,int r){
    findPS(arr,n);
    // for(auto x:PS)cout<<x<<" ";
    if(l!=0)return (PS[r-1]-PS[l-2]);
    else return PS[r];
}

int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<getSum(arr,n,2,5);
}