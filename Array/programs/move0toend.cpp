#include<iostream>
using namespace std;
int main(){
    int arr[]={10,0,0,1,0,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[count]);
            count++;
        }
    }
    for(auto x:arr)cout<<x<<" ";
}