#include<iostream>
using namespace std;

//odd-even or -ve+ve or 01
void partition_neg_pos(int arr[],int n)//hoares partition
{
    int i=-1,j=n;
    while(true){
        do{i++;}while(arr[i]<0);//for even arr[i]%2==0//for 0 arr[i]==0
        do{j--;}while(arr[j]>=0);//for odd arr[i]%2!=0//for 1 arr[i]==1
        if(i>=j)return;
        swap(arr[i],arr[j]);
    }

}
int main(){
    int a[]={-10,4,-12,5};
    int n=sizeof(a)/sizeof(a[0]);
    partition_neg_pos(a,n);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
}