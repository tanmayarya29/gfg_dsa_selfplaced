#include<bits/stdc++.h>
using namespace std;
int find_intersection(int a[],int b[],int na,int nb){
    unordered_set<int> s={a,a+na};
    int cnt=0;
    for(int i=0;i<nb;i++){
        if(s.find(b[i])!=s.end()){
            cnt++;s.erase(b[i]);
        }
    }
    return cnt;
}
int main(){
    int a[]={1,2,2,2,1,4,5,5};
    int b[]={1,2,2,6};
    int na=sizeof(a)/sizeof(a[0]);
    int nb=sizeof(b)/sizeof(b[0]);
    cout<<find_intersection(a,b,na,nb)<<endl;
}