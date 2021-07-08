// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    size_t sz;
list< pair<int, int> > keys;
unordered_map< int , list< pair<int, int> >::iterator> info;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int capacity)
    {
        // code here
        sz = capacity;
    keys.clear();
    info.clear();
        
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        int value = -1;
    if(info.find(key) != info.end()) {
        auto itr = info[key];
        value = itr->second;
        keys.erase(itr);
        keys.push_front( make_pair(key, value) );
        info[key] = keys.begin();
    }
    return value;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here
        if(info.find(key) == info.end()) {
        if(sz == keys.size()){
            auto last = keys.back();
            info.erase(last.first);
            keys.pop_back();
        }
    }
    else {
        keys.erase( info[key] );
    }
    keys.push_front( make_pair(key, value) );
    info[key] = keys.begin();
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends