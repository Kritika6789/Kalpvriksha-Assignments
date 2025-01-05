#include<stdio.h>
int greet(){
    int value=5;
   return value;
}
int main(){
 int (*ptr)()=greet;
 printf("%d",ptr());
 return 0;

}