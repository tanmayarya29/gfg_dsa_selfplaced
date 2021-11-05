#include<iostream>
#include<climits>
using namespace std;
///including 0 .else dont substract -1 from final result
int rep_elem(int a[],int n)//#1
{
    int sum=0,maxElem=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=a[i];
        maxElem=max(a[i],maxElem);
    }
    return (sum-(maxElem*(maxElem+1)/2))/(n-1-maxElem);
}

int rep_elem2(int arr[],int n)//#2
{
    	int slow = arr[0]+1, fast = arr[0]+1;

	do{
		slow = arr[slow]+1;
		fast = arr[arr[fast]]+1;
	
	}while(slow != fast);
	
	slow = arr[0]+1;

	while(slow != fast)
	{
		slow = arr[slow]+1;
		fast = arr[fast]+1;
	}
	return slow-1;
}
int main(){
    int arr[]={1,1,0,1,1,1,1};//(12-10)/(6-4)=2/2=1
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<rep_elem(arr,n)<<endl;
    cout<<rep_elem2(arr,n);
}