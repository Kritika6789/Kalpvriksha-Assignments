#include<stdio.h>
int main(){
    int x=10;
    float y=5.5;
    void *ptr;
    ptr=&y;
    printf("value is %.1f",*(float*)ptr);
    return 0;
}