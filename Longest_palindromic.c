#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
int str_length(char *str){
    int index=0;
    while(str[index]!='\0'){
        index++;
    }
    return index;
}
char *reverse(char *str){
    
    int length=str_length(str);
    char *str1=(char*)malloc((length+1)*sizeof(char));
    for(int index=0;index<length;index++){
        str1[index]=str[index];
    }
    int start=0;
    int end=length-1;
    while(start<end){
        int temp=str1[start];
        str1[start]=str1[end];
        str1[end]=temp;
        start++;
        end--;
    }
    return str1;
}
void longestPalindromeString(char *str,int index,int length,char*ans,int *max_length){
if(index==length){
    return;
}
printf("%d-%d\n",index,length);
int temp=index;
int end=length-1;
bool ispalindrome=false;
for(int index1=end;index1>=index;index1--){
    if(str[index1]==str[index]){
        int temp1=index;
        int temp2=index1;
      while(temp1<=temp2){
        if(str[temp1]==str[temp2]){
            temp1++;
            temp2--;
            ispalindrome=true;
        }
        else{
            ispalindrome=false;
            break;
        }
      }
      if(ispalindrome){
       int l=index1-index+1;
       if(l>*max_length){
        *max_length=l;
        int j=0;
        for(int i=index;i<=index1;i++){
            ans[j++]=str[i];
        }
        ans[j]='\0';
       }
       break;
      }
    }
    else{
        continue;
    }
}
longestPalindromeString(str,index+1,length,ans,max_length);
}
int main(){
    char *str=(char*)malloc(100*sizeof(char));
    printf("Enter string1:");
    scanf("%s",str);
    // char *reverse_string=(char*)malloc(100*sizeof(char));
    // reverse_string=reverse(str);
    printf("string:%s\n",str);
    // printf("reversed string:%s",reverse_string);
    int length1=str_length(str);
    int max_length=INT_MIN;
    char *ans=(char*)malloc((length1+1)*sizeof(char));
    longestPalindromeString(str,0,length1,ans,&max_length);

    printf("Output: %s",ans);
    return 0;
}