#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
void solve(char *str){
    int length=strlen(str);
    bool isadded[26]={false};
    char ans[length+1];
    int i=0;
    for(int index=0;index<length;index++){
        if(!isadded[(str[index]-'a')]){
            ans[i++]=str[index];
            isadded[str[index]-'a']=true;
        }
    }
    ans[i]='\0';
    printf("ans: %s",ans);
}
int main() {
    // Write C code here
    // printf("Try programiz.pro");
    char *str=(char*)malloc(100*sizeof(char));
    printf("Enter string");
    scanf("%s",str);
    solve(str);

    return 0;
}