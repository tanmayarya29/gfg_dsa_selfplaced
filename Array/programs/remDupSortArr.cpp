#include<iostream>
using namespace std;
int main(){
    int arr[]={10,10,10,10,30,30,30};
    int n=sizeof(arr)/sizeof(arr[0]);
    //
    // int runnElem=arr[0],indexOf1stOccurence=0;
    // for(int i=1;i<n;i++){
    //     if(runnElem!=arr[i]){
    //         arr[indexOf1stOccurence+1]=arr[i];
    //         indexOf1stOccurence+=1;
    //         runnElem=arr[i];
    //     }
    // }
    // cout<<"\nNo of distinct elements: "<<indexOf1stOccurence+1
    // for(int i=0;i<=indexOf1stOccurence;i++)cout<<arr[i]<<" ";

    //
    int res=1;
    for (int i=1;i<n;i++){
        if(arr[i]!=arr[res-1]){
            arr[res]=arr[i];
            res++;
        }
    }
    for(int i=0;i<res;i++){
        cout<<arr[i]<<" ";
    }
}