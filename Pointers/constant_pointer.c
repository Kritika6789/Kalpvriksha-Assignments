#include<stdio.h>
int main(){
    int x=10;
    int y=16;
    int *const ptr=&x;
    printf("value pointed by ptr:%d\n",*ptr);
    *ptr=15;
    printf("value pointed by ptr:%d\n",*ptr);
    ptr=&y; //gives error
    printf("value pointed by ptr:%d",*ptr);
    return 0;
}