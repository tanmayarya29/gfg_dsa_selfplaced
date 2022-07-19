#include<bits/stdc++.h>
using namespace std;

//crud
int main(){
    fstream file;
    file.open("test.txt",ios::app);
    file.is_open()?file<<"hello\n":cout<<"file cant be opened!";
    file.close();
}