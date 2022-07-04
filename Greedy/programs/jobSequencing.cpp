#include<bits/stdc++.h>
using namespace std;

struct jobs{
    int deadline;
    int profit;
};

bool mycomp(jobs a,jobs b){
    return a.profit>b.profit;//descending order
}

int main(){
    int slots=5;
    jobs arr[]={
        {4,50},
        {1,5},
        {1,20},
        {5,10},
        {5,80}
    };
    sort(arr,arr+slots,mycomp);

    jobs res[slots]={{0,0}};

    res[arr[0].deadline-1]=arr[0];
    for(int i=1;i<slots;i++){
        int tempDeadlin=arr[i].deadline-1;
        while(tempDeadlin>=0){
            if(res[tempDeadlin].deadline==0){
                res[tempDeadlin]=arr[i];
                break;
            }
            tempDeadlin--;
        }
    }

    for(int i=0;i<slots;i++){
        cout<<i+1<<" "<<res[i].deadline<<"-"<<res[i].profit<<endl;
    }



}