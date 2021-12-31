#include<bits/stdc++.h>
using namespace std;
int countDist(int arr[],int n){
    unordered_set<int> s={arr,arr+n};
    return s.size();
}
int main(){
    int arr[]={1,2,2,1,4,5,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<countDist(arr,n)<<endl;
}