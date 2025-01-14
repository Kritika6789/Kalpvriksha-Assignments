// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
int string_length(char *str){
    int index=0;
    while(str[index]!='\0'){
        index++;
    }
    return index;
}
int max(int value1,int value2){
    return value1>value2?value1:value2;
}
void longest_word(char* str){
    int length=string_length(str);
    int ans=INT_MIN;
    int count=0;
    int start=-1;
    int end=-1;
    int ans_start=-1;
    int ans_end=-1;
    for(int index=0;index<length;index++){
        if(str[index]!=' '){
            if(start==-1){
                start=index;
            }
            count++;
        }
        else{
            if(end==-1){
                end=index-1;
            }
            if(count>ans){
                ans=count;
                ans_start=start;
                ans_end=end;
            }
            count=0;
            start=-1;
            end=-1;
        }
    }
    if(start==-1){
        printf("Empty string");
        return;
    }
    if(end==-1){
                end=length-1;
    }
     if(count>ans){
                ans=count;
                ans_start=start;
                ans_end=end;
            }
    int length1=ans_end-ans_start+1;
    char *result=(char*)malloc((length1+1)*sizeof(char));
    int i=0;
    for(int index=ans_start;index<=ans_end;index++){
       result[i++]=str[index];
    }
    printf("%s",result);
}
int main() {
    // Write C code here
    // printf("Try programiz.pro");
    char *str=(char*)malloc(100*sizeof(char));
    printf("Enter string:");
    scanf("%[^\n]",str);
    longest_word(str);

    return 0;
}