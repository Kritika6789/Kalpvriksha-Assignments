// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct queue queue;
struct queue{
    int *array;
    int top;
    int size;
};
bool isEmpty(queue **q1){
    return (*q1)->top==-1;
}
bool isFull(queue **q1){
    int capacity=((*q1)->size)-1;
    return (*q1)->top==capacity;
}
void sizeOfQueue(queue **q1){
    if(isEmpty(&(*q1))){
        printf("size:%d\n",0);
        return;
    }
    printf("size:%d\n",((*q1)->top)+1);
}
void display(queue **q1){
     if(isEmpty(&(*q1))){
        printf("Empty queue\n");
        return;
    }
    int endIndex=(*q1)->top;
    for(int index=0;index<=endIndex;index++){
        printf("%d ",(*q1)->array[index]);
    }
    printf("\n");
}
void enqueue(queue **q1){
    if(isFull(&(*q1))){
        printf("Queue Full\n");
        return;
    }
    int data;
    printf("Enter data:");
    scanf("%d",&data);
    ((*q1)->top)++;
    (*q1)->array[(*q1)->top]=data;
}
void reverse(queue **q1,queue **q2){
    while((*q1)->top!=-1){
        int value=(*q1)->array[(*q1)->top];
        ((*q1)->top)--;
        ((*q2)->top)++;
        (*q2)->array[(*q2)->top]=value;
    }
    int value=(*q2)->array[(*q2)->top];
    ((*q2)->top)--;
    printf("Deleted %d from queue\n",value);
    while((*q2)->top!=-1){
        int value=(*q2)->array[(*q2)->top];
        ((*q2)->top)--;
        ((*q1)->top)++;
        (*q1)->array[(*q1)->top]=value;
    }
}
void dequeue(queue **q1,queue **q2){
    if(isEmpty(&(*q1))){
        printf("Empty queue\n");
        return;
    }
    reverse(&(*q1),&(*q2));
}
void peek(queue **q1){
     if(isEmpty(&(*q1))){
        printf("Empty queue\n");
        return;
    }
    printf("Peek element:%d\n",(*q1)->array[0]);
}
int main() {
    queue *q=(queue*)malloc(sizeof(queue));
    int capacity;
    printf("Enter size");
    scanf("%d",&capacity);
    q->array=(int*)malloc(capacity*sizeof(int));
    q->size=capacity;
    q->top=-1;
    queue *q2=(queue*)malloc(sizeof(queue));
    q2->array=(int*)malloc(capacity*sizeof(int));
    q2->size=capacity;
    q2->top=-1;
    printf("Enter 1:Enqueue\n");
    printf("Enter 2:Dequeue\n");
    printf("Enter 3:Peek\n");
    printf("Enter 4:isEmpty\n");
    printf("Enter 5:size\n");
    printf("Enter 6:isFull\n");
    printf("Enter 7:display\n");
    printf("Enter -1:Exit\n");
    int choice;
    while(1){
        printf("Enter choice:");
        scanf("%d",&choice);
        if(choice==1){
            enqueue(&q);
        }
        else if(choice==2){
            dequeue(&q,&q2);
        }
        else if(choice==3){
            peek(&q);
        }
        else if(choice==4){
            if(isEmpty(&q)){
                printf("Empty Queue\n");
            }
            else{
                printf("Not Empty\n");
            }
        }
        else if(choice==5){
            sizeOfQueue(&q);
        }
        else if(choice==6){
            if(isFull(&q)){
                printf("Now Queue is Full\n");
            }
            else{
                printf("Queue is not full\n");
            }
        }
        else if(choice==7){
            display(&q);
        }
        else{
            break;
        }
        
    }
    

    return 0;
}