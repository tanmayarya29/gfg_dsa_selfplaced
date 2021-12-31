#include<bits/stdc++.h>
using namespace std;

int longest_subarr_with_givensum(int arr[], int n,int sum)
{
    unordered_map<int,int> us;
    int len=0;
    int prefix_sum = 0;
    for(int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if(prefix_sum==sum){
          len=i+1;}
         if(us.find(prefix_sum) == us.end()){
        us.insert({prefix_sum,i});
          }
          if(us.find(prefix_sum-sum) != us.end()) len=max(len,i-us[prefix_sum-sum]);
    }
    return len;
}
int main(){
    int arr[]={5,8,3,-13,14,-1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=11;
    cout<<longest_subarr_with_givensum(arr,n,sum);
}