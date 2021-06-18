#include<iostream>
using namespace std;

int count1(bool arr[],int n){
    int maxTillNow=0,count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            count=0;
        }
        else{
            count++;
            maxTillNow=max(count,maxTillNow);
        }
    }
    return maxTillNow;
}

int main(){
    bool arr[]={0,0,1,1,1,1,0,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<count1(arr,n);
}
