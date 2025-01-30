// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node node;
struct node{
    int data;
    node *next;
};
typedef struct queue queue;
struct queue{
    node *front;
    node *rear;
};
bool isEmpty(queue **q){
    return (*q)->front==NULL;
}
void enqueue(queue **q){
    node *newNode=(node*)malloc(sizeof(node));
    if(!newNode){
        printf("Queue is Full now\n");
        return;
    }
    int value;
    printf("Enter value:");
    scanf("%d",&value);
    newNode->data=value;
    newNode->next=NULL;
    if((*q)->front==NULL){
        (*q)->front=newNode;
        (*q)->rear=newNode;
        return;
    }
    ((*q)->rear)->next=newNode;
    (*q)->rear=newNode;
}
void dequeue(queue **q){
    if(isEmpty(&(*q))){
      printf("Empty Queue\n");
      return;
    }
    node *temp=(*q)->front;
    int value=temp->data;
    (*q)->front=temp->next;
    temp->next=NULL;
    free(temp);
    if((*q)->front==NULL){
        (*q)->rear=NULL;
    }
    printf("Deleted %d from Queue\n",value);
}
void peek(queue **q){
    if((*q)->front==NULL){
        printf("Empty List\n");
        return;
    }
    printf("Peek Element:%d\n",((*q)->front)->data);
}
void size(queue **q){
    if((*q)->front==NULL){
        printf("Empty List\n");
        return;
    }
    int length=0;
    node *temp=(*q)->front;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    printf("size:%d\n",length);
}
void display(queue **q){
    if((*q)->front==NULL){
        printf("Empty List\n");
        return;
    }
    node *temp=(*q)->front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main() {
    queue *q=(queue*)malloc(sizeof(queue));
   q->front=NULL;
   q->rear=NULL;
    printf("Enter 1:Enqueue\n");
    printf("Enter 2:Dequeue\n");
    printf("Enter 3:Peek\n");
    printf("Enter 4:isEmpty\n");
    printf("Enter 5:size\n");
    printf("Enter 6:display\n");
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
            size(&q);
        }
        else if(choice==6){
            display(&q);
        }
        else{
            break;
        }
        
    }

    return 0;
}