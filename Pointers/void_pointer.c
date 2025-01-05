#include<stdio.h>
int main(){
    int value1=10;
    float value2=5.5;
    void *ptr;
    ptr=&value2;
    printf("value is %.1f",*(float*)ptr);
    return 0;
}