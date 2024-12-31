#include<stdio.h>
int solve1(int B,int N,int M){
    int pow=1;
    for(int i=0;i<N;i++){
     pow=pow*B;
     pow=pow%M;
    }
    return pow;
}
int main(){
    int B,N,M;
    do{
    printf("Enter value such that M>1 and N>=0\n");
    printf("Enter the value of base:");
    scanf("%d",&B);
    printf("Enter the value of exponent:");
    scanf("%d",&N);
    printf("Enter the value of modulus:");
    scanf("%d",&M);}while(M<1 ||N<0);
    int x=solve1(B,N,M);
    printf("ans:%d",x);
    return 0;
}