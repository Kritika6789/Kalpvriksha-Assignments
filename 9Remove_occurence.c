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
void remove_occurence(char *str,char ch){
    int length=str_length(str);
    char *result=(char*)malloc(100*sizeof(char));
    int result_index=0;
    for(int index=0;index<length;index++){
        if(str[index]!=ch){
             result[result_index++]=str[index];
        }
    }
    result[result_index]='\0';
    printf("Output:%s",result);
}
int main() {
    // Write C code here
    char*str=(char*)malloc(100*sizeof(char));
    printf("Enter string:");
    scanf("%[^\n]",str);
    char ch;
    printf("Enter character to remove from string:");
      scanf("\n");
    scanf("%c",&ch);
    remove_occurence(str,ch);

    return 0;
}