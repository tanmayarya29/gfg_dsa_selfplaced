#include <bits/stdc++.h>
using namespace std;

void printNByK(int arr[], int n, int k)
{
    unordered_map<int,int> m;
    
    for(int i=0;i<n;i++)
        m[arr[i]]++;
    for(auto e: m)
        if(e.second>n/k)
            cout<<e.first<<" ";
    
}

int main()
{
    int arr[] = {10, 10, 20, 30, 20, 10,10};
   
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=2;
    printNByK(arr, n, k);
}