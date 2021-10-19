#include<iostream>
using namespace std;
int peak_elem(int arr[],int n){
    int low=0,high=n-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if((mid==0 || arr[mid-1]<=arr[mid])&&(mid==n-1||arr[mid+1]<=arr[mid]))
            return mid;
        if(mid>0&&arr[mid-1]>=arr[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}
int main(){
    int arr[]={1,2,30,4,5,6,7,100,90,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<arr[peak_elem(arr,n)];
}