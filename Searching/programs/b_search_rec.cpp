#include <iostream>
using namespace std;

int b_search(int arr[],int low,int high,int key){//height = ceil of log2n
    if(low>high)
        return -1;
    int mid=(low+high)/2;
    if(arr[mid]==key)
        return mid;
    else if(arr[mid]>key)
        return b_search(arr,low,mid-1,key);
    else
        return b_search(arr,mid+1,high,key);
}


int main(){
    int arr[]={1,3,5,7,9},n=5,elem=9;
    cout<<b_search(arr,0,4,elem);//give the index of the element

}