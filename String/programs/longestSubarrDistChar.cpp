#include <bits/stdc++.h> 
using namespace std; 

int longestDistinct(string str) 
{ 
	int n = str.length(); 
	int res = 0;
	vector<int> prev(256,-1);
	int i=0;
	for (int j = 0; j < n; j++){
	    i=max(i,prev[str[j]]+1);
	    int maxEnd=j-i+1;
	    res=max(res,maxEnd);
	    prev[str[j]]=j;
	} 
	return res; 
} 

int main() 
{ 
	string str = "geeksforgeeks"; 
	int len = longestDistinct(str); 
	cout << "The length of the longest distinct characters substring is "<< len; 
	return 0; 
} 
