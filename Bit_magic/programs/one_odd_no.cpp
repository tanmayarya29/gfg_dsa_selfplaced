#include <iostream>
using namespace std;

int findOdd(int arr[],int n){
    int res=0;//x^0=x
    for(int i=0;i<n;i++){
        res^=arr[i];
    }
    return res;
}

int missingOddNofromSeq(int arr[],int n){//xor of all the nos and xor 1 to n+1 (coz number other than missing will b twice n become 0)
    int res=0;//x^0=x
    for(int i=0;i<n;i++){
        res^=arr[i];
    }
    for(int i=1;i<=n+1;i++)res^=i;
    return res;
}

int main(){
    int arr[]={1,1,2,2,2,3,3,3,3,4,4},n=11;
    cout<<findOdd(arr,n)<<endl;

    int arr2[]={1,4,5,2};
    int n2=4;
    cout<<missingOddNofromSeq(arr2,n2)<<endl;



}