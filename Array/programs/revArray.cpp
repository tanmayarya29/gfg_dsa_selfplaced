#include <iostream>
using namespace std;
int main(){
    int arr[]={5,1,3,2,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n/2; i++)
    {
        swap(arr[i],arr[n-i-1]);
    }

    for(auto x:arr)cout<<x<<" ";
    
}