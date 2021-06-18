#include<iostream>
using namespace std;
//moores mooting algorithm
int findMajority(int arr[],int n){
//find a candidate
    int res=0,count=1;
    for(int i=1;i<n;i++){
        if(arr[res]==arr[i]){
            count++;
        }else count--;
        if(count==0){
            res=i;count=1;
        }
    }
//check if candidate is actually a majority
    count=0;
    for(int i=0;i<n;i++){
        if(arr[res]==arr[i])count++;
    }
    if(count<n/2)res=-1;
    return res;
}


int main(){
    int arr[]={8,8,6,6,6,4,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<findMajority(arr,n);

}