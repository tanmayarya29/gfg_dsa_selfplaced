#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target){
    int n=nums.size();
    int l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(nums[mid]<target)
            l=mid+1;
        else
            r=mid-1;
        if(l==r && nums[l]==target)
            break;
    }
    return {-1,-1};
}

int main(){
    vector<int> nums={5,7,7,8,8,10};
    int target=8;
    vector<int> ans=searchRange(nums,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}