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

bool isFull(stack *q){
    int capacity=(q->size)-1;
    return q->rear==capacity;
}
void enstack(stack **q1,stack **q2,int value){
    if(isEmpty(*q1)){
        (*q1)->front=0;
        (*q1)->rear=0;
        (*q1)->array[(*q1)->rear]=value;
        return;
    }
   (*q2)->front=0;
   (*q2)->rear=0;
   (*q2)->array[(*q2)->rear]=value;
   int startIndex=(*q1)->front;
   int endIndex=(*q1)->rear;
   for(int index=startIndex;index<=endIndex;index++){
       ((*q2)->rear)++;
       (*q2)->array[(*q2)->rear]=(*q1)->array[index];
   }
   stack *temp=*q1;
   *q1=*q2;
   *q2=temp;
}
void push(stack **q1,stack **q2){
    if(isFull(*q1)){
        printf("stack overflow\n");
        return;
    }
    int data;
    printf("Enter data:");
    scanf("%d",&data);
    enstack(&(*q1),&(*q2),data);
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
    printf("Deleted element %d from stack \n",data);
   
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
    stack *q1=(stack*)malloc(sizeof(stack));
    stack *q2=(stack*)malloc(sizeof(stack));
    q1->size=capacity;
    q1->front=-1;
    q1->rear=-1;
    q1->array=(int*)malloc(capacity *sizeof(int));
    q2->size=capacity;
    q2->front=-1;
    q2->rear=-1;
    q2->array=(int*)malloc(capacity*sizeof(int));
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
            push(&q1,&q2);
        }
        else if(choice==2){
            pop(&q1);
        }
        else if(choice==3){
            peek(&q1);
        }
        else if(choice==4){
            if(isEmpty(q1)){
                printf("stack is \n");
            }
            else{
                printf("not empty\n");
            }
        }
        else if(choice==5){
            if(isFull(q1)){
                printf("stack full\n");
            }
            else{
                printf("not full\n");
            }
        }
        else if(choice==6){
            print(&q1);
        }
        else if(choice==7){
            size(&q1);
        }
        else{
            break;
        }
    }

    return 0;
}