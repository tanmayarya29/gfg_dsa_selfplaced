#include <iostream>
using namespace std;

int b_search(int arr[],int elem,int n){
    int low=0,high=n-1,mid;
    while(low<=high){
        mid=(low+high)/2;
    if(elem==arr[mid])
        return mid;
    else if(elem>mid){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
    }
    return -1;
}

int main(){
    int arr[]={1,3,5,7,9},n=5,elem=0;
    cout<<b_search(arr,elem,n);//give the index of the element
}