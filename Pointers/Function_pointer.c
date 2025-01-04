#include<stdio.h>
int greet(){
    int x=5;
   return x;
}
int main(){
 int (*ptr)()=greet;
 printf("%d",ptr());
 return 0;

}