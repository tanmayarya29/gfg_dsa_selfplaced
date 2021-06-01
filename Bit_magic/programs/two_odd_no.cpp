#include<iostream>
using namespace std;

void find2Odd(int arr[],int n){
    int XOR=0,res1=0,res2=0;
    for(int i=0;i<n;i++)XOR^=arr[i];
    int sn=(XOR&(~(XOR-1)));//rt most set bit
    for(int i=0;i<n;i++){
        if((arr[i]&sn)!=0)res1^=arr[i];
        else res2^=arr[i];
    }
    cout<<res1<<" "<<res2<<endl;
}

int main(){
    int arr[]={1,1,2,3,3,4,7,7};
    int n=8;
    find2Odd(arr,n);
}