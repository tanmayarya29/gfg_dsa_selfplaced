#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    int timer = 0;
void dfs(int u, vector<int>adj[], vector<vector<int>>&ans,
vector<int>&low, vector<int>&disc, stack<int>&s, vector<bool>&presentInS) {

disc[u] = low[u] = timer;
timer++;
s.push(u);
presentInS[u] = true;
for (auto v : adj[u]) {
if (disc[v] == -1) {
dfs(v, adj, ans, low, disc, s, presentInS);
low[u] = min(low[v], low[u]);
}
else if (presentInS[v]) {
low[u] = min(low[u], disc[v]);
}
}

if (low[u] == disc[u]) {
vector<int>temp;
while (s.top() != u && !s.empty()) {
temp.push_back(s.top());
presentInS[s.top()] = false;
s.pop();
}
if (!s.empty()) {
temp.push_back(s.top());
presentInS[s.top()] = false;
s.pop();
sort(temp.begin(), temp.end());
ans.push_back(temp);
}
}
}
vector<vector<int>> tarjans(int V, vector<int> adj[])
{
vector<vector<int>>ans;
stack<int>s;
vector<int>low(V, -1);
vector<int>disc(V, -1);
vector<bool>presentInS(V, false);

for (int i = 0; i < V; i++) {
if (disc[i] == -1)
dfs(i, adj, ans, low, disc, s, presentInS);
}
sort(ans.begin(), ans.end());
return ans;
}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends