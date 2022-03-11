#include<iostream>
using namespace std;

int index_of_first(int arr[],int elem,int n){
    int low=0,high=n-1,mid;
    while(low<=high){
    mid=(low+high)/2;
    if(elem>arr[mid]){
        low=mid+1;
    }
    else if(elem<arr[mid]){
        high=mid-1;
    }
    else
    {if(mid==0 || arr[mid-1]!=arr[mid])
        {
            return mid;
        }
    else high=mid-1;}
    }

    return -1;
}

int index_of_last(int arr[],int elem,int n){
    int low=0,high=n-1,mid;
    while(low<=high){
    mid=(low+high)/2;
    if(elem>arr[mid]){
        low=mid+1;
    }
    else if(elem>arr[mid]){
        high=mid-1;
    }
    else
    {if(mid==n-1 || arr[mid+1]!=arr[mid])
        {
            return mid;
        }
    else low=mid+1;}
    }

    return -1;
}

int occr_in_sorted(int arr[],int n,int key){
    int first=index_of_first(arr,key,n);
    if(first==-1)
    {
        return 0;
    }
    return (index_of_last(arr,key,n)-first+1);
}
int main()
{
    int arr[]={1,2,3,4,5,5,5,5,5,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=5;
    cout<<occr_in_sorted(arr,n,key);

}