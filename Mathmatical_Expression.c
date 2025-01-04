#include<stdio.h>
long long int calculate(long long int Base,long long int Exponent,long long int Modulus){
    if(Exponent==0){
        return 1;
    }
    long long int ans=calculate(Base,Exponent/2,Modulus);
    //multiplying temp 2 times
    ans=(ans%Modulus)*(ans%Modulus);
    if((Exponent%2)!=0){
       ans=(ans*Base)%Modulus;
    }
    return ans%Modulus;
}
int main(){
    long long int Base,Exponent,Modulus;
    do{
    printf("Enter value such that Modulus>1, Exponent>=0, Base>=0 \n");
    printf("Base(B):");
    scanf("%lld",&Base);
    printf("Exponent(E):");
    scanf("%lld",&Exponent);
    printf("Modulus(M):");
    scanf("%lld",&Modulus);
    } while(Modulus<1 || Exponent<0 || Base<0);  //If user enter correct input then only loop will break and  calculate function will be called
     if(Base==Modulus){
        printf("Result:%lld",0);
    }
    else{
    long long int result=calculate(Base,Exponent,Modulus);
    printf("Result:%lld",result);
    }
    return 0;
}