#include<iostream>
using namespace std;
//pivot last element or swap the given pivot with last element to make it last element
int lamuto_partition(int arr[],int l,int h){//O n timt n O 1 space
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

int main(){
    int arr[]={1,8,3,9,4,5,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<lamuto_partition(arr,0,n-1);
}