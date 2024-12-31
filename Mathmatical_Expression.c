#include<stdio.h>
int calculate(int B,int N,int M){
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
    printf("Base(B):");
    scanf("%d",&B);
    printf("Exponent(E):");
    scanf("%d",&N);
    printf("Modulus(M):");
    scanf("%d",&M);}while(M<1 ||N<0);
    int result=calculate(B,N,M);
    printf("Result:%d",result);
    return 0;
}