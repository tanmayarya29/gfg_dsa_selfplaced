#include<iostream>
using namespace std;
void reverse(int arr[],int low,int high){
    while(low<high){
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
}
void LRD(int arr[],int n,int d){
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}

/*

vector<int> rotateLeft(int d, vector<int> vec) {
    for (int i = 0; i < d; i++)
    {
        // adding first element at
        // the end of vector
        vec.push_back(vec[0]);
        // removing first element
        vec.erase(vec.begin());
    }
    return vec;
}
*/

int main(){
    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int d=4;
    LRD(arr,n,d);
    for(auto x:arr)cout<<x<<" ";

}