// C++ program to demonstrate implementation of our 
// own hash table with chaining for collision detection 
#include<bits/stdc++.h>
using namespace std;

struct MyHash
{
    int BUCKET;
    list<int> *table;
    MyHash(int b)
    {
        BUCKET = b;
        table = new list<int>[BUCKET];
    }
    void insert(int k)
    {
        int i = k % BUCKET;
        table[i].push_back(k);
    }
    bool search(int k)
    {
        int i = k % BUCKET;
        for (auto x : table[i])
           if (x == k)
              return true;
        return false;      
    }
    void remove(int k)
    {
        int i = k % BUCKET;
        table[i].remove(k);
    }
};

	// Driver method to test Map class 
	int main() 
	{ 
	    MyHash mh(7);
	    mh.insert(10);
	    mh.insert(20);
	    mh.insert(15);
	    mh.insert(7);
	    cout << mh.search(10) << endl;
	    mh.remove(15);
	    cout << mh.search(15);
	} 
