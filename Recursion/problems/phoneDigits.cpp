// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++
static vector<char> keypad[] ={
        {}, {},        
        { 'a', 'b', 'c' },
        { 'd', 'e', 'f' },
        { 'g', 'h', 'i' },
        { 'j', 'k', 'l' },
        { 'm', 'n', 'o' },
        { 'p', 'q', 'r', 's'},
        { 't', 'u', 'v' },
        { 'w', 'x', 'y', 'z'}
    };
class Solution
{
    public:
    
    
    static vector<string> ans;
    
    void findCombinations(vector<char> keypad[],
                      int input[], string res, int index)
{
    // If processed every digit of key, print result
    if (index == -1) {
        // cout << res << " ";
        ans.push_back(res);
        return;
    }
 
    // Stores current digit
    int digit = input[index];
 
    // Size of the list corresponding to current digit
    int len = keypad[digit].size();
 
    // One by one replace the digit with each character in the
    // corresponding list and recur for next digit
    for (int i = 0; i < len; i++) {
        findCombinations(keypad, input, keypad[digit][i] + res, index - 1);
    }
}
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        findCombinations(keypad,a,"",N-1);
        return ans;
        
        
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends