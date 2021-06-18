#include<iostream>
using namespace std;

int trapWater(int arr[],int n){
    int res=0;
    int lmax[n],rmax[n];
    lmax[0]=arr[0];
    for(int i=1;i<n-1;i++){
        lmax[i]=max(lmax[i-1],arr[i]);
    }
    rmax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        rmax[i]=max(rmax[i+1],arr[i]);
    }
    for(int i=1;i<n-1;i++){
        res+=(min(lmax[i],rmax[i])-arr[i]);
    }
    return res;
}


int main(){
    int arr[]={5,0,6,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<trapWater(arr,n);
    }