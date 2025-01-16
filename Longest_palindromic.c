// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>
void str_cpy(char *dest,char *src){
    int index=0;
    while(1){
        dest[index]=src[index];
        if(dest[index]=='\0'){
       break;
}
        index++;
    }
  
}
int str_len(char *s){
    int index=0;
    while(s[index]!='\0'){
        index++;
    }
    return index;
}
bool ispalindrome(char *ans,int length){
    int start=0;
    int end=length-1;
    while(start<=end){
        if(ans[start]==ans[end]){
            start++;
            end--;
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
void longestPalindrome(char* s) {
    int length=str_len(s);
    char **ans=(char**)malloc(1000*sizeof(char*));
    char *a=(char*)malloc(100*sizeof(char));
    int index=0;
    for(int i=0;i<length;i++){
        int k=0;
        for(int j=i;j<length;j++){
          a[k++]=s[j];
          a[k]='\0';
          int l1=str_len(a);
          ans[index]=(char*)malloc((l1)*sizeof(char));
          str_cpy(ans[index],a);
          index++;
        }
    }
    int longest=INT_MIN;
   int longest_index=-1;
    for(int i=0;i<index;i++){
       int length=str_len(ans[i]);
       if(ispalindrome(ans[i],length)){
           if(length>longest){
               longest=length;
               longest_index=i;
           }
       }
    }
    if(longest_index!=-1){
    printf("%s",ans[longest_index]);
    }
    else{
        printf("not exist");
    }
}
int main() {
    char *s=(char*)malloc(100*sizeof(char));
    printf("Enter string:");
    scanf("%s",s);
    longestPalindrome(s);

    return 0;
}
