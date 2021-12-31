#include <iostream>
using namespace std;
struct myHash{//librarry funcion uses dummy node for keeping track of deleted value pointers to overcome -1 and -2 preesence in the values
    int *arr;
    int cap,size;
    myHash(int c){
        cap=c;
        size=0;
        arr=new int[cap];
        for(int i=0;i<cap;i++)
            arr[i]=-1;
    }
    int hash(int key){
        return key%cap;
    }
    bool insert(int key){
        if(size==cap)
            return false;
        int i=hash(key);
        while(arr[i]!=-1 && arr[i]!=-2 && arr[i]!=key)
            i=(i+1)%cap;
        if(arr[i]==key){
            return false;
        }
        else{
            arr[i]=key;
            size++;
            return true;
        }
        
    }
    bool search(int key){
        int h=hash(key);
        int i=h;
        while(arr[i]!=-1){
            if(arr[i]==key)
                return true;
            i=(i+1)%cap;
            if(i==h)
                return false;       
        }
        return false;
    }

    bool erase(int key){
        int h=hash(key);
        int i=h;
        while(arr[i]!=-1){
            if(arr[i]==key){
                arr[i]=-2;
                return true;
            }
            i=(i+1)%cap;
            if(i==h)
                return false;
        }
        return false;
    }
};
int main(){
    myHash mh(7);
    mh.insert(49);
    mh.insert(56);
    mh.insert(72);
    if(mh.search(56)==true)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    mh.erase(56);
    if(mh.search(56)==true)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}