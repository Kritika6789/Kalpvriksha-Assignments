// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
    int data;
    node *next;
};
void insertNode(int value,node **head,node **tail){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=value;
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
        *tail=newNode;
        return;
    }
    (*tail)->next=newNode;
    *tail=newNode;
}
void sort(node **head){
    node *temp1=*head;
    node *temp2=*head;
    while(temp1!=NULL){
        temp2=*head;
        while(temp2->next!=NULL){
            if(temp2->data>temp2->next->data){
                int temp=temp2->data;
                temp2->data=temp2->next->data;
                temp2->next->data=temp;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}
void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main() {
    // Write C code here
    node *head=NULL;
    node *tail=NULL;
    insertNode(1,&head,&tail);
    insertNode(2,&head,&tail);
    insertNode(0,&head,&tail);
    // insertNode(1,&head,&tail);
    // insertNode(2,&head,&tail);
    // insertNode(0,&head,&tail);
    // insertNode(0,&head,&tail);
    // insertNode(1,&head,&tail);
    // insertNode(0,&head,&tail);
    // insertNode(2,&head,&tail);
    // insertNode(0,&head,&tail);
    // insertNode(2,&head,&tail);
    sort(&head);
  print(head);
    

    return 0;
}
