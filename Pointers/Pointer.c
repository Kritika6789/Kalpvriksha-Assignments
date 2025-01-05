#include<stdio.h>
int main(){
    int value1=10;
    int value2=20;
    int *ptr1,*ptr2;
    ptr1=&value1;
    ptr2=&value2;
    printf("address:%p\n",(void*)&value1);
    printf("address:%p\n",&value1);
    printf("address:%p\n",(void*)&value2);
    int *ptr3=NULL;
    printf("address pointed by NULL pointer%d\n",*ptr3);
    
    return 0;
}