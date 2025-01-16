#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
bool isletter(char ch){
    if(ch>='a' && ch<='z' || ch>='A' && ch<='Z'){
        return true;
    }
    return false;
}
void solve(char *str){
    int length=strlen(str);
    int count=0;
    bool isspace1=true;
    for(int index=0;index<length;index++){
      if(isletter(str[index])){
          if(isspace1){
          isspace1=false;
          }
          continue;
      }
      else{
          if(!isspace1){
              count++;
              isspace1=true;
          }
      }
    }
    if(!isspace1){
        count++;
    }
    printf("Number of words: %d",count);
}
int main() {
   
    char *str=(char*)malloc(100*sizeof(char));
    
    printf("Enter string: ");
    scanf("%[^\n]",str);
    solve(str);

    return 0;
}