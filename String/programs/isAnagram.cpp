#include <iostream>
using namespace std;
bool isAnagram(string &s1,string &s2)//ispermutation
{
    int n=s1.length(),m=s2.length();
    if(n!=m)
        return false;
    int arr[256]={0};//for only small alphabets use size 26 and - 'a'
    for(int i=0;i<n;i++)
    {
        arr[s1[i]]++;
        arr[s2[i]]--;
    }
    for(int i=0;i<26;i++)
    {
        if(arr[i]!=0)
            return false;
    }
    return true; 
}
int main(){
    string s1="civic",s2="viicc";
    if(isAnagram(s1,s2))
        cout<<"Yes";
    else
        cout<<"No";
}