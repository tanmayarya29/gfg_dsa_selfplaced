#include<bits/stdc++.h>
using namespace std;
/*
Application of Stack
1. Function calls
2. Checking balanced parenthesis
3. Reversing
4. Infix to prefix/postfix
5. Evaluating postfix/prefix
6. Stack span problem and its variations
7. Undo/Redo or Forward/Backward
*/
struct MyStack
{
    int top;
    int capacity;
    int *array;
    MyStack(int cap)
    {
        top = -1;
        capacity = cap;
        array = new int[cap];
    }
    //functions
    bool isEmpty()
    {
        return top == -1;
    }
    void push(int item)
    {
        if(top == capacity - 1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        array[++top] = item;
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow"<<endl;
            return INT_MIN;
        }
        return array[top--];
    }
    int peek()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow"<<endl;
            return INT_MIN;
        }
        return array[top];
    }
    int size()
    {
        return top + 1;
    }
};

struct MyDynamicStack{
    vector<int> v;
    //functions
    void push(int item){
        v.push_back(item);
    }
    int pop(){
        if(v.size() == 0){
            cout<<"Stack Underflow"<<endl;
            return INT_MIN;
        }
        int item = v.back();
        v.pop_back();
        return item;
    }
    int peek(){
        if(v.size() == 0){
            cout<<"Stack Underflow"<<endl;
            return INT_MIN;
        }
        return v.back();
    }
    int size(){
        return v.size();
    }
    bool isEmpty(){
        return v.size() == 0;
    }
};
int main(){
    MyStack s(5);
    s.push(5);
    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}