#include<iostream>
using namespace std;
int partition(int arr[],int l,int h,int p){
    int temp[h-l+1],index=0;
    for(int i=l;i<=h;i++){
        if(arr[i]<arr[p]){
            temp[index]=arr[i];
            index++;
        }
    }
    for(int i=l;i<=h;i++){
        if(arr[i]==arr[p]){
            temp[index]=arr[i];
            index++;
        }
    }
    int res=l+index-1;
    for(int i=l;i<=h;i++){
        if(arr[i]>arr[p]){
            temp[index]=arr[i];
            index++;
        }
    }
    for(int i=l;i<=h;i++){
        arr[i]=temp[i-l];
    }
    return res;
}
int main(){
    int arr[]={5,3,12,8,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<partition(arr,0,n-1,0);
}