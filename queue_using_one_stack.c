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
bool isEmpty(queue **q){
    return (*q)->top==-1;
}
bool isFull(queue **q){
    int capacity=((*q)->size)-1;
    return (*q)->top==capacity;
}
void push(queue **q,int value){
    if((*q)->top==-1){
        ((*q)->top)++;
        (*q)->array[(*q)->top]=value;
        return;
    }
    int data=(*q)->array[(*q)->top];
    ((*q)->top)--;
    push(&(*q),value);
    ((*q)->top)++;
    (*q)->array[(*q)->top]=data;
}
void enqueue(queue **q){
   if(isFull(&(*q))){
       printf("Queue Full \n");
       return;
   }
   int data;
   printf("Enter data:");
   scanf("%d",&data);
   push(&(*q),data);
}
void dequeue(queue **q){
    if(isEmpty(&(*q))){
        printf("Queue Empty\n");
        return;
    }
    int data=(*q)->array[(*q)->top];
    ((*q)->top)--;
    printf("Delete %d from queue\n",data);
}
void peek(queue **q){
    if(isEmpty(&(*q))){
        printf("Queue Empty\n");
        return;
    }
    printf("Peek Element:%d\n",(*q)->array[(*q)->top]);
}
void sizeOfQueue(queue **q){
    if(isEmpty(&(*q))){
        printf("size:%d",0);
        return;
    }
    printf("size:%d",((*q)->top+1));
}
void display(queue **q){
      if(isEmpty(&(*q))){
        printf("Queue Empty\n");
        return;
    }
    int endIndex=(*q)->top;
    for(int index=endIndex;index>=0;index--){
        printf("%d ",(*q)->array[index]);
    }
    printf("\n");
}
int main() {
    queue *q=(queue*)malloc(sizeof(queue));
    int capacity;
    printf("Enter size");
    scanf("%d",&capacity);
    q->array=(int*)malloc(capacity*sizeof(int));
    q->size=capacity;
    q->top=-1;
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