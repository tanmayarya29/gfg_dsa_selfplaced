#include<iostream>
using namespace std;

void FreqSortArr(int arr[],int n){
    int freq=1,i=1;
    while(i<n){
    while(i<n && arr[i]==arr[i-1]){
       freq++;i++;
    }
    cout<<arr[i-1]<<" "<<freq<<endl;
    i++;
    freq=1;
}
if(n==1||arr[n-1]!=arr[n-2]){
    cout<<arr[n-1]<<" "<<1;
}
}

int main(){
    int arr[]={1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    FreqSortArr(arr,n);
}