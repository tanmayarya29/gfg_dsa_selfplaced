#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(int arr[],int n){
    vector<int> v;
    stack<int>s;
    s.push(arr[n-1]); v.push_back(-1);
    for(int i=n-2;i>=0;i--){
        while(s.empty()==false && s.top()<=arr[i])
            s.pop();
        int ng=s.empty()?-1:s.top();
        v.push_back(ng);
        s.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    return v;
}

int main() 
{ 
    int arr[]={5,15,10,8,6,12,9,18};
    int n=8;
    for(int x: nextGreater(arr,n)){
        cout<<x<< " ";   
    }
    return 0; 
}
