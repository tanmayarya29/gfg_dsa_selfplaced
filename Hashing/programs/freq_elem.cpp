#include<bits/stdc++.h>
using namespace std;
int freq_elem(int arr[],int n,int elem){
    unordered_map<int,int> s;
    for(int i=0;i<n;i++){
        s[arr[i]]++;
    }
    return s[elem];
}
int main(){
    int arr[]={1,2,2,1,4,5,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<freq_elem(arr,n,5)<<endl;
}