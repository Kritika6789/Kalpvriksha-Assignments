#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

bool solve(char *str1,char *str2){
    int length1=strlen(str1);
    int length2=strlen(str2);
    if(length1!=length2){
        return false;
    }
    int index1=0;
    bool isrotated=false;
    for(int index2=0;index2<length2;index2++){
        if(str1[index1]==str2[index2]){
            int start1=(index1+1)%length1;
            int start2=(index2+1)%length2;
            int end1=index1;
            int end2=index2;
           while(start1!=end1 && start2!=end2){
               if(str1[start1]==str2[start2]){
                   isrotated=true;
                   start1=(start1+1)%length1;
                   start2=(start2+1)%length2;;
               }
               else{
                   isrotated=false;
                   break;
               }
           }
           if(isrotated && start1==end1 && start2==end2){
            //   printf("Enter true");
               return true;
           }
        }
    }
    return false;
}
int main() {
    printf("Enter string1:");
   char *str1=(char*)malloc(100*sizeof(char));
   scanf("%s",str1);
   printf("Enter string2:");
   char *str2=(char*)malloc(100*sizeof(char));
   scanf("%s",str2);
    
    bool ans=solve(str1,str2);
    if(ans){
        printf("true");
    }
    else{
        printf("false");
    }

    return 0;
}