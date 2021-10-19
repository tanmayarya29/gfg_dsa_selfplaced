#include<iostream>
using namespace std;

int srch_srt_rot(int arr[],int n,int key){
    int low=0,high=n-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==key)
            return mid;
        if(arr[0]<=arr[mid]){
            if(key>=arr[0] && key<=arr[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        else{
            if(key>=arr[mid] && key<=arr[n-1])
                low=mid+1;
            else
                high=mid-1;
        }
    }return -1;
}

int main(){
    int arr[]={100,500,10,20,30,40,50};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=10;
    cout<<srch_srt_rot(arr,n,key);
    
}