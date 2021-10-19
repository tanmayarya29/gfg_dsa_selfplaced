#include <iostream>
using namespace std;

int index_of_first(int arr[],int elem,int n){
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
    {if(mid==0 || arr[mid-1]!=arr[mid])
        {
            return mid;
        }
    else high=mid-1;}
    }

    return -1;
}

int main(){
    int arr[]={0,5,5,7,5},n=5,elem=5;
    cout<<index_of_first(arr,elem,n);//give the index of the element
}