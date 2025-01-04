#include<stdio.h>
#include<stdbool.h>
#include<string.h>
bool solve(char *string1,char *string2){
  if(strcmp(string1,string2)==0){
    return true;
  }
  int length_of_string1=strlen(string1);
  int length_of_string2=strlen(string2);
  int itr=0;
  for(int i=0;i<length_of_string1;){
    if(string1[i]==string2[itr]){
        int temp=itr+1;
        i++;
        while(temp<length_of_string2 && i<length_of_string1){
            if(string1[i]==string2[temp]){
              i++;
              temp++;
            }
            else{
                   break;
            }
        }
        if(temp==length_of_string2){
            return true;
        }
    }
    i++;
  }
  return false;
}
int main(){
    char *string1="stringmatchingmat";
    char *string2="ringt";
    bool issubstring=solve(string1,string2);
    if(issubstring){
        printf("YES");
    }
    else{
        printf("NO");
    }
}