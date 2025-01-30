// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct queue queue;
struct queue{
    int *array;
    int front;
    int rear;
    int size;
};
bool isEmpty(queue **q){
    return (*q)->front==-1;
}
bool isFull(queue **q){
    int capacity=(*q)->size;
    return (*q)->rear==capacity-1;
}
void sizeOfQueue(queue **q){
    if((*q)->front==-1){
        printf("size: %d\n",0);
        return;
    }
    printf("size: %d\n",((*q)->rear-(*q)->front)+1);
}
void display(queue **q){
    int startIndex=(*q)->front;
    int endIndex=(*q)->rear;
    if(startIndex==-1){
        printf("Empty Queue\n");
        return;
    }
    for(int i=startIndex;i<=endIndex;i++){
        printf("%d ",(*q)->array[i]);
    }
    printf("\n");
}
void enqueue(queue **q){
    if(isFull(&(*q))){
        printf("Queue is full\n");
        return;
    }
     int data;
     printf("Enter data:");
     scanf("%d",&data);
    if((*q)->front==-1){
        (*q)->front=0;
    }
    ((*q)->rear)++;
    (*q)->array[(*q)->rear]=data;
}
void dequeue(queue **q){
    if(isEmpty(&(*q))){
        printf("Queue is Empty\n");
        return;
    }
    if((*q)->front==(*q)->rear){
        int data=(*q)->array[(*q)->front];
        printf("Deleted %d from queue\n",data);
        (*q)->front=-1;
        (*q)->rear=-1;
        return;
    }
    int data=(*q)->array[(*q)->front];
    (*q)->front++;
    printf("Deleted %d from queue\n",data);
}
void peek(queue **q){
    if((*q)->front==-1){
        printf("Empty Queue\n");
        return;
    }
    int data=(*q)->array[(*q)->front];
    printf("Front Element:%d\n",data);
}
int main() {
    queue *q=(queue*)malloc(sizeof(queue));
    int capacity;
    printf("Enter size");
    scanf("%d",&capacity);
    q->array=(int*)malloc(capacity*sizeof(int));
    q->size=capacity;
    q->front=-1;
    q->rear=-1;
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
            dequeue(&q);
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