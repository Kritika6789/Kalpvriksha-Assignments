#include<stdio.h>
int main(){
    int x=10;
    int y=15;
    const int *ptr=&x;
    printf("value pointed by %d\n",*ptr);
    // *ptr=15; cannot change value
    ptr=&y;
    printf("value pointed by %d\n",*ptr);

    //constant pointer to constant value
    const int *const ptr1=&y;
    printf("value pointed by %d",*ptr1);
    return 0;



}