#include <bits/stdc++.h>
using namespace std;
//min difference between minimum and maximum
int minDiff(int arr[],int n,int m){
    if(m>n)
        return -1;
    sort(arr,arr+n);
    int res=arr[m-1]-arr[0];
    for(int i=0;(i+m-1)<n;i++)
        res=min(res,arr[i+m-1]-arr[i]);
    return res;
}
 
int main() {
	
    int arr[]={7,3,2,4,9,12,56};
	int n=sizeof(arr)/sizeof(arr[0]);int m=3;
	cout<<minDiff(arr,n,m);
}