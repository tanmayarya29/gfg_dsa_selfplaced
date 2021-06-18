#include<iostream>
using namespace std;
//Window sliding-WS
//Max sum aubarray of size k
int WSmaxSumSubarrK(int arr[],int n,int k){
    int curr_sum=0;
    for(int i=0;i<k;i++){
        curr_sum+=arr[i];
    }
    int max_sum=curr_sum;
    for(int i=k;i<n;i++){
        curr_sum+=(arr[i]-arr[i-k]);
        max_sum=max(max_sum,curr_sum);
    }
    return max_sum;
}

//subarr of size k with sum = s
bool WSSumSSubarrK(int arr[],int n,int k,int s){
    int curr_sum=0;
    for(int i=0;i<k;i++){
        curr_sum+=arr[i];
    }
    for(int i=k;i<n;i++){
        if(curr_sum==s)return true;
        curr_sum+=(arr[i]-arr[i-k]);
    }
    return false;
}

//unsorted non-negetive nos subarr with sum = s
bool WSSumSSubarr(int arr[],int n,int sum){
    //s=start e=end
    int curr_sum=arr[0],s=0;
    for(int e=1;e<=n;e++){
        //clean the prev window
        while(curr_sum>sum && s<(e-1)){
            curr_sum-=arr[s];s++;
        }
    if(curr_sum==sum)return true;
    if(e<n)curr_sum+=arr[e];
    }
    return (curr_sum==sum);
}

int main(){
    int arr[]={1,8,30,-5,20,7};int s=45;int k=3;
    int arr2[]={1,4,20,3,10,5};int s2=15;
    int n=sizeof(arr)/sizeof(arr[0]);
    int n2=sizeof(arr2)/sizeof(arr[0]);
    cout<<WSmaxSumSubarrK(arr,n,k);
    cout<<WSSumSSubarrK(arr,n,k,s);
    cout<<WSSumSSubarr(arr2,n2,s2);
}