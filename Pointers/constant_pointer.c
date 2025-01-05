#include<stdio.h>
int main(){
    int val1=10;
    int val2=16;
    int *const ptr=&val1;
    printf("value pointed by ptr:%d\n",*ptr);
    *ptr=15;
    printf("value pointed by ptr:%d\n",*ptr);
    // ptr=&val2; //gives error
    printf("value pointed by ptr:%d",*ptr);
    return 0;
}