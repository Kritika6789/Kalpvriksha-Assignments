#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
char *solve(char *s,bool isduplicate){
    if(!isduplicate){
           return s;
    }
    int length=strlen(s);
    char *ans=(char*)malloc(1000000*sizeof(char));
    int ans_index=0;
    bool isfound=false;
    for(int index=0;index<length;){
       if(index==length-1){
         ans[ans_index++]=s[index];
          break;
       }
         else if(s[index]==s[index+1]){
            isfound=true;
            index+=2;
            continue;
         }
         else{
            ans[ans_index++]=s[index];
            index++;
         }
    }
    ans[ans_index]='\0';
    strcpy(s,ans);
    free(ans);
    return solve(s,isfound);

}
char* removeDuplicates(char* s) {
    bool isduplicate=true;
   char *ans=solve(s,isduplicate);
   return ans;
}
int main(){
    char *s=(char*)malloc(100*sizeof(char));
    printf("Enter string:");
    scanf("%s",s);
    char *ans=removeDuplicates(s);
    printf("output:%s",ans);
    return 0;
}