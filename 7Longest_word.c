// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
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
    int start=-1;
    int end=-1;
    int length=string_length(str);
    char *ans=(char*)malloc(100*sizeof(char));
    int i=0;
    int longest=INT_MIN;
    int start_index=-1;
    int end_index=-1;
    bool isletter=false;
    for(int index=0;index<length;index++){
        if(str[index]!=' '){
            if(start==-1){
                start=index;
                isletter=true;
            }
        }
        else{
            if(isletter && end==-1){
                end=index;
                int length=end-start;
                if(length>longest){
                    longest=length;
                    start_index=start;
                    end_index=end;
                    isletter=false;
                }
            }
            start=-1;
            end=-1;
        }
    }
     if(isletter && end==-1){
                end=length-1;
                int length=end-start+1;
                if(length>longest){
                    longest=length;
                    start_index=start;
                    end_index=end;
                }
            }
            if(start==-1 && end==-1){
                printf("Empty string");
            }
            else{
                  int index=0;
    for(int st=start_index;st<=end_index;st++){
        ans[index++]=str[st];
    }
    printf("%s",ans);
    }

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
