#include<bits/stdc++.h>
using namespace std;

bool pair_with_givensum(int arr[], int n, int sum)
{
    unordered_set<int> h;
    for(int i=0;i<n;i++)
    {
        if(h.find(sum-arr[i])!=h.end())
        {
            return true;
        }
        else h.insert(arr[i]);
    }
    return false;
}
int main(){
    int arr[]={1,2,5,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=1;
    cout<<pair_with_givensum(arr,n,sum);
}