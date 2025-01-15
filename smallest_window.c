#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
int min(int x,int y){
    return x>y?y:x;
}
int max(int x,int y){
    return x>y?x:y;
}
bool solve(char *str,char *pattern,int length,int p_length,int index,int *min_length,int *start,int *end){
    if(index==length){
        return true;
    }
    int array[p_length];
    for(int i=0;i<p_length;i++){
        array[i]=-1;
    }
    bool array1[length];
    for(int i=0;i<length;i++){
        array1[i]=false;
    }
    //byahhhhhhaajbcccc
    int count=0;
    int start_index=INT_MAX;
    int end_index=INT_MIN;
    for(int p_index=0;p_index<p_length;p_index++){
        for(int str_index=index;str_index<length;str_index++){
            if(pattern[p_index]==str[str_index]){
                if(array[p_index]==-1 && array1[str_index]==false){
                    array[p_index]=str_index;
                    array1[str_index]=true;
                    count++;
                    start_index=min(start_index,str_index);
                    end_index=max(end_index,str_index);
                    array[p_index]=str_index;
                    break;
                }
            }
        }
    }
    if(index==0 && count<p_length){
        return false;
    }
    if(count<p_length && *start==INT_MAX && *end==INT_MIN){
        return false;
    }
    if(count==p_length){
    int length2=end_index-start_index+1;
    if(*min_length>length2){
        *start=start_index;
        *end=end_index;
        *min_length=length2;
        
    }
    }
    // printf("%d\n",*min_length);
  return solve(str,pattern,length,p_length,index+1,min_length,start,end);
}
void print(char *str,int start,int end,int length){
    char *ans=(char*)malloc((length+1)*sizeof(char));
    int i=0;
    for(int index=start;index<=end;index++){
        ans[i++]=str[index];
    }
    ans[i]='\0';
    printf("output: %s",ans);
}
int main() {
    char *str=(char*)malloc(100*sizeof(char));
    printf("Enter string:");
    scanf("%[^\n]",str);
    int length=strlen(str);
    char *pattern=(char*)malloc(100*sizeof(char));
    printf("Enter Pattern:");
    scanf("\n");
    scanf("%s",pattern);
     int p_length=strlen(pattern);
     int min_length=INT_MAX;
     int s=-1;
     int e=-1;
      if(length<p_length){
        return printf(" ");
     }
    if(solve(str,pattern,length,p_length,0,&min_length,&s,&e)){
    print(str,s,e,min_length);
    }
    else{
        printf("substring do not exist");
    }
    return 0;
}