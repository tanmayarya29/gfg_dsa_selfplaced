// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
        // Your code here
        int m[256] = { 0 };
 
    // Answer
    int ans = INT_MAX; // length of ans
    int start = 0; // starting index of ans
    int count = 0;
   
    // creating map
    for (int i = 0; i < t.length(); i++) {
        if (m[t[i]] == 0)
            count++;
        m[t[i]]++;
    }
 
    // References of Window
    int i = 0;
    int j = 0;
 
    // Traversing the window
    while (j < s.length()) {
        // Calculations
        m[s[j]]--;
        if (m[s[j]] == 0)
            count--;
 
        // Condition matching
        if (count == 0) {
            while (count == 0) {
                // Soring ans
                if (ans > j - i + 1) {
                    ans = min(ans, j - i + 1);
                    start = i;
                }
                // Sliding I
                // Calculation for removing I
 
                m[s[i]]++;
                if (m[s[i]] > 0)
                    count++;
 
                i++;
            }
        }
        j++;
    }
 
    if (ans != INT_MAX)
        return s.substr(start, ans);
    else
        return "-1";
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends