#include<bits/stdc++.h>
using namespace std;
//set is based on red-black tree where as unordered_set is based on hash table
//it is used when we want to insert serch or delete in O(1) time on keys only for key-value pair use unordered map
int main(){
    unordered_set<int> s;//any permutation of inserted elements//operation is in O(1)
    //
    s.clear();
    s.insert(10);
    s.insert(5);
    s.insert(30);
    s.insert(20);
    for(auto it=s.begin();it!=s.end();it++)
        cout<<*it<<" ";
    cout<<s.size()<<endl;
    cout<<*s.find(5)<<endl;//return iterator to the element or end() if not found
    cout<<s.count(5)<<endl;//return 0 if element is present else 0  
    s.erase(5);
    auto x=find(s.begin(),s.end(),30);
    s.erase(x);
    // s.erase(s.begin(),s.end());//erase all elements
    cout<<s.size()<<endl;

}