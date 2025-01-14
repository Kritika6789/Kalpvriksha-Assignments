#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int str_length(char *str){
    int index=0;
    while(str[index]!='\0'){
        index++;
    }
    return index;
}
void str_concat(char *str1,char *str2){
    int length1=str_length(str1);
    int length2=str_length(str2);
    int final_length=length1+length2+1;
    str2=realloc(str2,final_length*sizeof(char));
    for(int index=0;index<length1;index++){
        str2[length2+index]=str1[index];
    }
    str2[final_length-1]='\0';
}
bool solve(char *str1,char *str2){
    str_concat(str2,str2);
    int length1=str_length(str1);
      int length2=str_length(str2);
      int str1_index=0;
      bool isfound=false;
    for(int str2_index=0;str2_index<length2;str2_index++){
      if(str2[str2_index]==str1[str1_index]){
        int temp1=str1_index+1;
        int temp2=str2_index+1;
          while(temp1<length1 && temp2<length2){
            if(str2[temp2]==str1[temp1]){
                isfound=true;
                 temp2++;
                 temp1++;
            }
            else{
                break;
            }
          }
          if(isfound && temp1==length1){
             return true;
          }
          else{
            isfound=false;
          }
      }
    }
    return false;

    
}
int main(){
    char *str1=(char*)malloc(100*sizeof(char));
    printf("Enter string:");
    scanf("%s",str1);
     char *str2=(char*)malloc(100*sizeof(char));
     printf("Enter string2:");
     scanf("%s",str2);
    if(solve(str1,str2)){
        printf("true");
    }
    else{
        printf("false");
    }
    return 0;
}