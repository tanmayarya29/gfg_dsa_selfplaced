#include<bits/stdc++.h>
using namespace std;

bool subarr_with0sum(int arr[], int n)
{
    unordered_set<int> us;
    int prefix_sum = 0;
    us.insert(0);
    for(int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if(us.find(prefix_sum) != us.end())
          return 1;
        if(prefix_sum==0)
          return 1;
        us.insert(prefix_sum);
    }
    return 0;
}
int main(){
    int arr[]={1,2,5,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<subarr_with0sum(arr,n);
}