#include<iostream>
using namespace std;
//
//pivot last element or swap the given pivot with last element to make it last element
int lamuto_partition(int arr[], int l, int h)
{   
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}
//quick select
int kth_smallest(int arr[],int n,int k){
    int l=0,r=n-1;
    while(l<=r){
        int p=lamuto_partition(arr,l,r);
        if(p==k-1)
            return arr[p];
        else if(p<k-1)
            l=p+1;
        else
            r=p-1;
    }
    return -1;
}

int main(){
    int arr[]={10,4,5,8,11,6,26};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=5;
    cout<<kth_smallest(arr,n,k);
}