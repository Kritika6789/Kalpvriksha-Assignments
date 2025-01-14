// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
int str_length(char *str){
    int index=0;
    while(str[index]!='\0'){
        index++;
    }
    return index;
}
void string_compression(char *str){
    int length=str_length(str);
    char *result=(char*)malloc(100*sizeof(char));
    int i=0;
    int count=1;
    for(int index=0;index<length-1;index++){
        if(str[index]==str[index+1]){
            count++;
        }
        else{
            result[i++]=str[index];
            if(count>1){
            result[i++]=(count+'0');
            }
            count=1;
        }
    }
     result[i++]=str[length-1];
     if(count>1){
            result[i++]=(count+'0');
            }
     result[i]='\0';
     printf("Compressed string: %s",result);
}
int main() {
    // Write C code here
    char *str=(char*)malloc(100*sizeof(char));
    printf("Enter string:");
    scanf("%s",str);
    string_compression(str);

    return 0;
}