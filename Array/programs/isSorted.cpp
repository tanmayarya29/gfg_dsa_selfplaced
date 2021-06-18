#include<iostream>
using namespace std;
bool isSorted(int arr[],int n){
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]<0)return 0;
    }
    return 1;
}
int main(){
    int arr[]={2,2,2,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<isSorted(arr,n);
}