#include<bits/stdc++.h>
using namespace std;
//map is red black tree based whereas unordered map is a hash table
int main(){
    unordered_map<string , int> m;
    m["tanmay"] = 1;//reference to the key is returned
    m["hello"] = 10;
    m.insert({"else",2});
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    if(m.find("tanmay") != m.end()){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
    m.at("tanmay") = 100;//returns the reference to the key
    cout<<m.count("tanmay")<<endl;//returns 1  keys if found else 0
    cout<<m.size()<<endl;//returns the number of elements in the map
    m.erase("hello");//erases the key
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    m.erase(m.begin(),m.end());//erases all the elements
}