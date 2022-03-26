#include <iostream>
#include <cmath>
#include <bits/stdc++.h> 
#include <climits>
#include <deque>
using namespace std;


void printMax(int arr[], int n, int k)
{
  
    deque<int> dq;

  
   
    for (int i = 0; i < k; ++i) {
        
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back(); 

        
        dq.push_back(i);
    }

   
    for (int i=k; i < n; ++i) {
        
        cout << arr[dq.front()] << " ";

        
        while ((!dq.empty()) && dq.front() <= i - k)
            dq.pop_front();

       
        while ((!dq.empty()) && arr[i] >= arr[dq.back()])
            dq.pop_back();

       
        dq.push_back(i);
    }

    
   cout << arr[dq.front()];
}

int main()
{
	int arr[] = { 20, 40, 30, 10, 60}, n = 5;
    int k = 3;
    
    printMax(arr, n, k);
    
	return 0;
}