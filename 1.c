#include <stdio.h>
int main(){
    int X,Y,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&X,&Y);
        //logic// min(2x,3y)
        int ans=3*X>2*Y?2*Y:3*X;
        printf("%d\n",ans);
    }
}a