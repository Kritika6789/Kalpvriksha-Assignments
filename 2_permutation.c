#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//abc
//abc acb bac bca cab cba

void print(char **ans,int total){
      for(int row=0;row<total;row++){
        printf("%s ",ans[row]);
    }
    printf("\n");
}
void swap(char *ch1,char*ch2){
    int temp=*ch1;
    *ch1=*ch2;
    *ch2=temp;
}
void str_cpy(char *dest, char *source){
    int index=0;
    while(1){
        dest[index]=source[index];
        if(dest[index]=='\0'){
            break;
        }
        index++;
    }
}
void permutation(char *str,int index,int length,char **ans,int*ans_index){
    if(index==length){
        str_cpy(ans[(*ans_index)++],str);
        return;
    }
    for(int i=index;i<length;i++){
        // printf("Enter\n");
     swap(&str[index],&str[i]);
     permutation(str,index+1,length,ans,ans_index);
    //  printf("Enter\n");
    swap(&str[index],&str[i]);
    }
}
int main(){
    char *str=(char*)malloc(100*sizeof(char));
    printf("Enter string");
    scanf("%s",str);
    int length=strlen(str);
    int total=1;
    for(int count=1;count<=length;count++){
        total=total*count;
    }
   char **ans=(char**)malloc(total*sizeof(char*));
   for(int row=0;row<total;row++){
    ans[row]=(char*)malloc((length+1)*sizeof(char));
   }
   int ans_index=0;
    permutation(str,0,length,ans,&ans_index);
    print(ans,ans_index);
    return 0;
}