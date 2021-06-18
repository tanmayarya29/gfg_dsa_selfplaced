#include<iostream>
#include<climits>
using namespace std;

//maximum value of arr[j]-arr[i] st j>i
int maxVal(int arr[],int n){//n
    int currMax=arr[1]-arr[0],minVal=arr[0];
    for(int i=1;i<n;i++){
        currMax=max(currMax,arr[i]-minVal);
        minVal=min(minVal,arr[i]);
    }
    return currMax;
}
int main(){
    int arr[]={2,3,10,6,4,8,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<maxVal(arr,n);

}