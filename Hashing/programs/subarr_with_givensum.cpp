#include<bits/stdc++.h>
using namespace std;

bool subarr_with_givensum(int arr[], int n,int sum)
{
    unordered_set<int> us;
    int prefix_sum = 0;
    for(int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if(prefix_sum==sum)
          return 1;
        if(us.find(prefix_sum-sum) != us.end())
          return 1;
        us.insert(prefix_sum);
    }
    return 0;
}
int main(){
    int arr[]={5,8,3,13,6,-1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=22;
    cout<<subarr_with_givensum(arr,n,sum);
}