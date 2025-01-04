#include<stdio.h>
#include<stdlib.h>
int main(){
int *ptr=(int*)malloc(sizeof(int));
*ptr=10;
printf("value at location pointed by %d\n",*ptr);
free(ptr);
printf("value at location pointed after memory is deallocated %d",*ptr);
return 0;
}
