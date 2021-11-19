#include<iostream>
using namespace std;
//1st index
int hoare_partition(int arr[],int l,int h){//O n timt n O 1 space
    int pivot=arr[l];
    int i=l-1,j=h+1;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j)
            return j;
        swap(arr[i],arr[j]);
    }

}

int main(){
    int arr[]={5,3,8,4,2,7,1,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<hoare_partition(arr,0,n-1);
}