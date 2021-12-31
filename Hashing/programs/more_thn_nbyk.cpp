//for small n/k n large n
//O nk soln
/*
The Boyer-Moore voting algorithm is one of the popular optimal algorithms which
 is used to find the majority element among the given elements that have more than N/ 2 occurrences.
  This works perfectly fine for finding the majority element which takes 2 traversals over the given elements,
   which works in O(N) time complexity and O(1) space complexity.
*/
#include <bits/stdc++.h>
using namespace std;

void printNByK(int arr[], int n, int k)
{
    unordered_map<int,int> m;
    
    for(int i=0;i<n;i++){
        if(m.find(arr[i])!=m.end())
            m[arr[i]]++;
        else if(m.size()<k-1)
            m[arr[i]]=1;
        else
            for(auto x:m){
                x.second--;
                if(x.second==0)
                    m.erase(x.first);}
    }
    for(auto x:m){
        int count=0;
        for(int i=0;i<n;i++){
            if(x.first==arr[i])
                count++;
        
       }
        if(count>n/k)
            cout<<x.first<<" ";
    }
}

int main()
{
    int arr[] = {30, 10, 20, 20, 20, 10, 40, 30, 30};
   
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=4;
    printNByK(arr, n, k);
}