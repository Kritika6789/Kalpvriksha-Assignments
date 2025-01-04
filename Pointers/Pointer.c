#include<stdio.h>
int main(){
    int a=10;
    int b=20;
    int *ptr1,*ptr2;
    ptr1=&a;
    ptr2=&b;
    printf("address:%p\n",(void*)&a);
    printf("address:%p\n",&a);
    printf("address:%p\n",(void*)&b);
    int *ptr3=NULL;
    printf("address pointed by NULL pointer%d\n",*ptr3);
    
    return 0;
}