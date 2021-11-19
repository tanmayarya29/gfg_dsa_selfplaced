/*
1. Worst case - theta n^2
2. does min memory writes and can be useful where memory writes is costly
3. in place and not stable
4. useful in questions like find minimum swaps requires to sort an array
*/
#include<bits/stdc++.h> 
using namespace std; 
//hw 
//make it work for duplicates
//count minimum no of swaps
void cycleSortDistinct(int arr[], int n) 
{ 
    for(int cs=0;cs<n-1;cs++){
        int item=arr[cs];
        int pos=cs;
        for(int i=cs+1;i<n;i++)
            if(arr[i]<item)
                pos++;
        swap(item,arr[pos]);
        while(pos!=cs){
            pos=cs;
            for(int i=cs+1;i<n;i++)
                if(arr[i]<item)
                    pos++;
            swap(item,arr[pos]);
        }
    }
} 
  
int main() 
{ 
    int arr[] = { 20,40,50,10,30 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cycleSortDistinct(arr, n); 
   
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
        
    return 0; 
} 