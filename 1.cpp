#include <stdio.h>

struct p

{
int x;
char y;

};

int main(){
struct p p1[] = {1, 92, 3, 94, 5, 96};
struct p *ptr1 = p1;
int x = (sizeof(p1) / sizeof(struct p));
printf("%d %d\n", ptr1->x, (ptr1 + x - 1)->x);

}
