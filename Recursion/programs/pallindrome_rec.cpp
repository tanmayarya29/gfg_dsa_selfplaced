#include<iostream>
using namespace std;

bool isPal(string s,int beg,int end){//time n space O(n)
    if (beg>=end)return true;//beg cross end so beg>end//beg==end for odd so beg=end
    return s[beg]==s[end]&&isPal(s,beg+1,end-1);
    
}

int main(){
    string s="abcba";
    int n=s.length();
    cout<<isPal(s,0,n-1);

}