#include<iostream>
using namespace std;

//(0,1,2) 
//or (pivots occur together and smaller on left greater on right) 
//or (range of pivots occur together and smaller on left greater on right)

//dutch national flag algorithm
void partition_012(int arr[],int n)//theta n time theta 1 space
{
    int l=0,m=0,h=n-1;
    while(m<=h)
    {
        if(arr[m]==0)
        {
            swap(arr[l],arr[m]);
            l++;
            m++;
        }
        else if(arr[m]==1)
        {
            m++;
        }
        else
        {
            swap(arr[m],arr[h]);
            h--;
        }
    }
}
int main(){
    int a[]={0,1,2,1,0,1,2};
    int n=sizeof(a)/sizeof(a[0]);
    partition_012(a,n);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
}