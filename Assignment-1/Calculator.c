#include <stdio.h>
#include<string.h>
struct stack{
    int values[100];
    char operate[100];
    int top1;
    int top2;
};
  struct stack op;
  struct stack value;
int isdigit1(char ch){
    return ch>='0' && ch<='9';
}
int apply(int val1,int val2, char ch){
    if(ch=='+') return val1+val2;
    if(ch=='-') return val1-val2;
    if(ch=='*')  return val1*val2;
    if(ch=='/'){
        if(val1==0){
            printf("Error: Division by Zero");
            return -2;
        }
        float ans= val2/val1;
        return (int)ans;
    }
    return -1;
}
int precedence(char ch){
    if(ch=='*'|| ch=='/') return 2;
    if(ch=='+' || ch=='-') return 1;
    return 0;
}
int check(char ch){
 if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='('||ch==')' || ch-'0'>=0 && ch-'0'<=9) return 1;
    return 0;
}
void push1(char ch){ op.operate[++op.top1]=ch;}
void push2(int val){value.values[++value.top2]=val;}
int pop2(){  return value.values[value.top2--];}
char pop1(){ return op.operate[op.top1--];}
int implement(){
        int val1=pop2();
        int val2=pop2();
        char ch=pop1();
        int ans=apply(val1,val2,ch);
        return ans;
}
void evaluateExpression(char *s){
   int l=strlen(s);
      op.top1=-1;
     value.top2=-1;
     int isvalid=1;
     for(int i=0;i<l-1;i++){
        if(s[i]==' '){
            continue;
        }
       int res=check(s[i]);
        if(res==0){
            isvalid=0;
            break;
        }
     }
     if(!isvalid){
            printf("Error: Invalid Expression");
     }
     else{
        int isvalid=1;
        int iszero=0;
     for(int i=0;i<l;i++){
        if(s[i]==' '){
            continue;
        }
         else if(s[i]=='('){
             push1(s[i]);
         }
         else if(isdigit1(s[i])){
             int val=0;
             while(i<l && isdigit1(s[i])){
                 val=val*10+(s[i]-'0');
                 i++;
             }
             push2(val);
             i--;
         }
         else if(s[i]==')'){
            while(op.top1!=-1 && op.operate[op.top1]!='('){
                int ans=implement();
                if(ans==-1){
                    isvalid=0;
                    break;
                }
                 if(ans==-2){
                    iszero=1;
                    break;
                }
                else{
                push2(ans);
                }
            }
            op.top1=op.top1-1;
         }
         else{
            while(op.top1!=-1 && precedence(op.operate[op.top1])>=precedence(s[i])){
                int ans=implement();
                if(ans==-1){
                    isvalid=0;
                    break;
                }
                if(ans==-2){
                    iszero=1;
                    break;
                }
                else{
                push2(ans);
                }
            } 
              push1(s[i]);
            }
         }   
     if(isvalid){
     while(op.top1!=-1 ){
                int ans=implement();
                if(ans==-1){
                    isvalid=0;
                    break;
                }
                 if(ans==-2){
                    iszero=1;
                    break;
                }
                else{
                push2(ans);
                }
     }
     if(!iszero){
     if(op.top1!=-1){
        printf("Error:Invalid Expression");
     }
     else{
     printf("\n");
    printf("Ans: %d\n",value.values[0]);
     } }  }
     else{
        printf("Error:Invalid Expression");
     }  } 
     }
int main() {
    char s[100];
    printf("enter string");
    fgets(s,100,stdin);
    printf("%s \n",s);
    evaluateExpression(s);
    return 0;
}