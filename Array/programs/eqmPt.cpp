#include<bits/stdc++.h>
using namespace std;

bool hasEquillibriumPoint(int arr[],int n){
    int sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	int l_sum = 0;
	for(int i = 0; i < n; i++)
	{
		if(l_sum == sum - arr[i])
			return true;
		l_sum += arr[i];
		sum -= arr[i];
	}
	return false;
}

int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<hasEquillibriumPoint(arr,n);
}