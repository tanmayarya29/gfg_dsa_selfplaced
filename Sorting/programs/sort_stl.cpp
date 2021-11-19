#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

/*
stable soring algorithm - bubble sort, insertion sort, merge sort
unstable sorting algorithm - quick sort, heap sort, selection sort
*/

struct point{
        int x,y;
};
bool comparator(point a,point b){
return a.x>b.x;//descending acc to x coordinate
}

void sortingArr(){
    int arr[]={4,1,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    for(int x:arr)cout<<x<<" ";
    cout<<endl;
    //sort in descending order
    sort(arr,arr+n,greater<int>());
    for(int x:arr)cout<<x<<" ";
    cout<<endl;
}

void sortingVector(){
    vector<int> v={4,1,6,7};
    sort(v.begin(),v.end());
    for(int x:v)cout<<x<<" ";
    cout<<endl;
    //sort in descending order
    sort(v.begin(),v.end(),greater<int>());
    for(int x:v)cout<<x<<" ";
    cout<<endl;
}


void sortingStruct(){
    
    point arr[]={
        {4,1},
        {6,7},
        {1,4},
        {7,6}
    };
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n,comparator);
    for(point x:arr)cout<<x.x<<" "<<x.y<<endl;
    
}

int main(){
    //it sorts array,vector and deque
    sortingArr();
    sortingVector();
    sortingStruct();
    
}