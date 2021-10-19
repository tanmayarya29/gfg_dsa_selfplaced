#include<iostream>
using namespace std;

int sqrt_floor(int num){
    int low=1,high=num,ans;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid*mid==num)
            return mid;
        else if(mid*mid<num)
            {low=mid+1;
            ans=mid;}
        else
            high=mid-1;
    }
    return ans;
}

int main(){
    int num=10;
    cout<<sqrt_floor(num)<<endl;
}