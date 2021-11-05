#include<iostream>
#include<climits>
//*****
using namespace std;
double median(int arr1[],int arr2[],int n1,int n2){
    int beg=0,end=n1,mid;
    while(beg<=end){
        int i1=(beg+end)/2;
        int i2=(n1+n2+1)/2-i1;
        int min1=(i1==i2)?INT_MAX:arr1[i1];
        int min2=(i1==i2)?INT_MAX:arr2[i2];
        int max1=(i1==i2)?INT_MIN:arr1[i1-1];
        int max2=(i1==i2)?INT_MIN:arr2[i2-1];
        if(max1<=min2 && max2<=min1){
            if((n1+n2)%2==0){
                return (double)(max(max1,max2)+min(min1,min2))/2;
            }
            else{
                return (double)max(max1,max2);
            }
        }
        else if(max1>min2){
            end=i1-1;
        }
        else{
            beg=i1+1;
        }
    }
}
int main(){
    int arr1[]={1,3,5,7,9};
    int arr2[]={2,4,6,8,10};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    cout<<median(arr1,arr2,n1,n2);
}