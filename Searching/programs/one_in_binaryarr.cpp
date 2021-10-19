#include<iostream>
using namespace std;

int one_in_binarr(int arr[],int n){
    int low=0,high=n-1,mid;
    while(low<=high){
    mid=(low+high)/2;
    if(0==arr[mid]){
        low=mid+1;
    }
    else
    {if(mid==0 || arr[mid-1]!=arr[mid])
        {
            return n-mid;
        }
    else high=mid-1;}
    }

    return -1;
}

int main()
{
    int arr[]={0,0,0,1,1,1,1,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<one_in_binarr(arr,n);
}