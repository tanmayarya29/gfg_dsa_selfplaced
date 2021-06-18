#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[]={5,20,12,20,8};
    int runnLar=arr[0],runn2ndLar=-1;
    for(int i=0;i<5;i++){
        if(runnLar<arr[i]){
            runn2ndLar=runnLar;
            runnLar=arr[i];
        }else if(runnLar!=arr[i]){
            if(runn2ndLar<arr[i])runn2ndLar=arr[i];
        }

    }
    cout<<runn2ndLar<<"-"<<runnLar;

}