#include<iostream>
using namespace std;

int count_subset(int arr[],int n,int sum){//theta of 2^n
    if(n==0)return sum==0?1:0;
    return count_subset(arr,n-1,sum)+count_subset(arr,n-1,sum-arr[n-1]);

}
int main(){
    int arr[]={10,20,15},sum=25,n=3;
    cout<<count_subset(arr,n,sum);
}