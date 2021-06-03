#include<iostream>
using namespace std;

void genSub(string s,string curr="",int i=0)
//gen all subsequence of string//all char in string are diff//for n -> 2^n subsets/seq
{
    if(i==s.length()){
        cout<<curr<<" ";
        return;
    }
    genSub(s,curr,i+1);
    genSub(s,curr+s[i],i+1);
}

int main(){
    string s="abc";//
    genSub(s);
}