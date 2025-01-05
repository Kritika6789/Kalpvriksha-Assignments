#include<stdio.h>
int main(){
    int value1=10;
    int value2=15;
    const int *ptr=&value1;
    printf("value pointed by %d\n",*ptr);
    // *ptr=15; cannot change value
    ptr=&value2;
    printf("value pointed by %d\n",*ptr);

    //constant pointer to constant value
    const int *const ptr1=&value2;
    printf("value pointed by %d",*ptr1);
    return 0;



}