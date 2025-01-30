// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node node;
struct node{
    int data;
    node *next;
};
typedef struct stack stack;
struct stack{
    node *top;
    int length;
};
bool isEmpty(stack **s){
  return (*s)->top==NULL;
}
void size(stack **s){
   printf("size:%d\n",(*s)->length);
}
void push(int value,stack **s){
    node *newNode=(node*)malloc(sizeof(node));
    if(!newNode){
        printf("Stack overflow\n");
        return;
    }
    newNode->data=value;
    newNode->next=NULL;
    (*s)->length=(*s)->length+1;
    if((*s)->top==NULL){
        (*s)->top=newNode;
        return;
    }
    newNode->next=(*s)->top;
    (*s)->top=newNode;
}
void pop(stack **s){
    if(isEmpty(&(*s))){
        printf("Stack underflow\n");
        return;
    }
    (*s)->length=(*s)->length-1;
    node *temp=(*s)->top;
    (*s)->top=temp->next;
    temp->next=NULL;
    free(temp);
    
}
void peek(stack **s){
    if(((*s)->top)==NULL){
        printf("Empty stack\n");
        return;
    }
    printf("top:%d\n",((*s)->top)->data);
}
void print(stack **s){
    node *temp=(*s)->top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main() {
    stack *s=(stack*)malloc(sizeof(stack));
    printf("enter 1:Push\n");
    printf("enter 2:Pop\n");
    printf("enter 3:Peek\n");
    printf("enter 4:isEmpty\n");
    printf("enter 5:size\n");
    printf("enetr 6:Print\n");
    printf("enter -1:Exit\n");
    int choice;
    while(1){
        printf("Enter choice:");
        scanf("%d",&choice);
        if(choice==1){
            int value;
            printf("Enter value:");
            scanf("%d",&value);
            push(value,&s);
        }
        else if(choice==2){
            pop(&s);
        }
        else if(choice==3){
           peek(&s);   
        }
        else if(choice==4){
            if(isEmpty(&s)){
                printf("Empty stack\n");
            }
            else{
                printf("Not Empty\n");
            }
        }
        else if(choice==5){
            size(&s);
        }
        else if(choice==6){
            print(&s);
        }
        else{
            break;
        }
    }

    return 0;
}