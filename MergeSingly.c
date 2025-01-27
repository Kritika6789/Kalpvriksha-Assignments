// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
    int data;
    node *next;
};
void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
node *split(node *head){
    if(head==NULL){
        return head;
    }
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    node *temp=slow->next;
    slow->next=NULL;
    return temp;
}
node *merge(node *first,node *second){
  if(first==NULL){
    return second;
  }
  if(second==NULL){
    return first;
  }
  if(first->data<=second->data){
    first->next=merge(first->next,second);
    return first;
  }
  else{
    second->next=merge(first,second->next);
    return second;
  }
}
node *mergeSort(node *head){
    if(head==NULL|| head->next==NULL){
        return head;
    }
    node *second=split(head);
    head=mergeSort(head);
    second=mergeSort(second);
    return merge(head,second);
}
void insertNode(int dataue,node **head,node **tail){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=dataue;
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
        *tail=newNode;
        return;
    }
    (*tail)->next=newNode;
    *tail=newNode;
}
int main() {
  node *head=NULL;
  node *tail=NULL;
    int choice;
    while(1){
        printf("Enter choice:");
        scanf("%d",&choice);
        if(choice==1){
            int data;
            printf("Enter data:");
            scanf("%d",&data);
            insertNode(data,&head,&tail);
        }
        else{
            break;
        }
    }
    print(head);
    node *result=mergeSort(head);
    print(result);

    return 0;
}