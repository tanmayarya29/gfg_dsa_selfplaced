/*
proper prefix of abcd - "", a, ab, abc
suffix of abcd - "", d, cd, bcd, abcd

longest proper prefix suffix 
string - abacabad
         00101230
string - abbabb
         000123
*/
#include <bits/stdc++.h> 
using namespace std; 

// //naive O(n^3)
// int longPropPreSuff(string str, int n){
//     for(int len=n-1;len>0;len--){
//         bool flag=true;
//         for(int i=0;i<len;i++)
//             if(str[i]!=str[n-len+i])
//                 flag=false;
                
//         if(flag==true)
//             return len;
//     }
//     return 0;
// }
// void fillLPS(string str, int *lps){
//     for(int i=0;i<str.length();i++){
//         lps[i]=longPropPreSuff(str,i+1);
//     }
// }

//efficient - O(n)
void fillLPS(string str, int *lps){
    int n=str.length(),len=0;
    lps[0]=0;
    int i=1;
    while(i<n){
        if(str[i]==str[len])
        {len++;lps[i]=len;i++;}
        else
        {if(len==0){lps[i]=0;i++;}
            else{len=lps[len-1];}
        }
    }
}
 
int main() 
{ 
    string txt = "abacabad";int lps[txt.length()];
    fillLPS(txt,lps);
    for(int i=0;i<txt.length();i++){
        cout<<lps[i]<<" ";
    }
    
    return 0; 
} 