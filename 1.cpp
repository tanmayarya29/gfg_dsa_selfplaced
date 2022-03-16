//ALTERNATE SORTING
#include<bits/stdc++.h>
using namespace std;

void alternateSorting(int arr[],int n){
    sort(arr,arr+n);//1,1,2,3,4,16->16,1,4,1,3,2
    int i=0,j=n-1;
    while(i<j){
        cout<<arr[j]<<" ";
        j--;
        cout<<arr[i]<<" ";
        i++;
    }
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    alternateSorting(arr,n);
}