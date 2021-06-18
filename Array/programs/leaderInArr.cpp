#include<bits/stdc++.h>
using namespace std;
//leader is one on right of which every elem is small
//ascendeing = last emen
//desceding = all elements

void leaderInArr(int arr[],int n){//n^2
     for(int i=0;i<n;i++){
     bool flag = false;
        for(int j=i+1;j<n;j++){
            if(arr[j]>=arr[i]){
                flag=true;
                break;
            }  
        }
        if(!flag){
                cout<<arr[i]<<" ";
        }
    }
}

void leaderInArr2(int arr[],int n){//n
    stack<int> st;
    int runningLeader=n-1;
    // cout<<arr[runningLeader]<<" ";
    st.push(arr[runningLeader]);
    for(int i=n-1;i>=0;i--){
        if(arr[i]>arr[runningLeader]){
            runningLeader=i;
            // cout<<arr[runningLeader]<<" ";
            st.push(arr[runningLeader]);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main(){
    int arr[]={7,10,4,10,6,5,2};
    int n=sizeof(arr)/sizeof(arr[0]);
//    leaderInArr(arr,n);
   leaderInArr2(arr,n);


}