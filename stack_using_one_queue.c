// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct stack stack;
struct stack{
    int *array;
    int front;
    int rear;
    int size;
};
bool isEmpty(stack *q){
    return ((q)->front==-1 || q->front>(q->rear));
}
void reverse(stack **q,int data){
    if((*q)->rear==-1|| isEmpty(*q)){
        (*q)->front=0;
        (*q)->rear=0;
        (*q)->array[(*q)->rear]=data;
        return;
    }
    int value=(*q)->array[(*q)->rear];
    (*q)->array[((*q)->rear)--];
    reverse(&(*q),data);
    ((*q)->rear)++;
    (*q)->array[(*q)->rear]=value;
}
bool isFull(stack *q){
    int capacity=(q->size)-1;
    return q->rear==capacity;
}
void push(stack **q){
    if(isFull(*q)){
        printf("stack overflow\n");
        return;
    }
    int data;
    printf("Enter data:");
    scanf("%d",&data);
    reverse(&(*q),data);
}
void print(stack **q){
    if((*q)->front==-1){
        printf("Empty stack\n");
    }
    int startIndex=(*q)->front;
    int endIndex=(*q)->rear;
    for(int index=startIndex;index<=endIndex;index++){
        printf("%d ",(*q)->array[index]);
    }
    printf("\n");
}
void pop(stack **q){
    if(isEmpty(*q)){
        printf("stack underflow\n");
        return;
    }
     if((((*q)->front)==(*q)->rear)){
          int data=(*q)->array[(*q)->front];
           printf("Deleted elelemtn %d from stack \n",data);
         (*q)->front=-1;
         (*q)->rear=-1;
         return;
         
     }
    int data=(*q)->array[(*q)->front];
    ((*q)->front)++;
    printf("Deleted elelemtn %d from stack \n",data);
   
}
void size(stack **q){
    if((*q)->front==-1){
        printf("size:%d",0);
        return;
    }
    int sizeOfstack=((*q)->rear)-((*q)->front)+1;
    printf("szie:%d\n",sizeOfstack);
}
void peek(stack **q){
    if((*q)->front==-1){
        printf("Empty stack\n");
        return;
    }
    printf("Peek Element:%d\n", (*q)->array[(*q)->front]);
}
int main() {
    int capacity;
    printf("Enter capacity:");
    scanf("%d",&capacity);
    stack *q=(stack*)malloc(sizeof(stack));
    q->size=capacity;
    q->front=-1;
    q->rear=-1;
    q->array=(int*)malloc(capacity *sizeof(int));
    int choice=-1;
    printf("Enter 1:Push\n");
    printf("Enter 2:Pop\n");
    printf("Enter 3:Peek\n");
    printf("Enter 4:isEmpty\n");
    printf("Enter 5:isFull\n");
    printf("Enter 6:print\n");
    printf("Enter 7:size\n");
    printf("Enter 8:Exit\n");
    while(1){
        printf("Enter choice");
        scanf("%d",&choice);
        if(choice==1){
            push(&q);
        }
        else if(choice==2){
            pop(&q);
        }
        else if(choice==3){
            peek(&q);
        }
        else if(choice==4){
            if(isEmpty(q)){
                printf("stack is \n");
            }
            else{
                printf("not empty\n");
            }
        }
        else if(choice==5){
            if(isFull(q)){
                printf("stack full\n");
            }
            else{
                printf("not full\n");
            }
        }
        else if(choice==6){
            print(&q);
        }
        else if(choice==7){
            size(&q);
        }
        else{
            break;
        }
    }

    return 0;
}