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
        (*tail)->next=*head;
        return;
    }
    newNode->next=(*head);
    (*tail)->next=newNode;
    *tail=newNode;
}
void print(node *head){
    node *temp=head;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
        if(temp==head){
             printf("%d ",temp->data);
            break;
        }
    }
    printf("\n");
}
void split(node **head1,node **tail1,node **head2,node **tail2){
    node *slow=*head1;
    node *fast=(*head1)->next;
    while(fast->next!=(*head1)){
        slow=slow->next;
        fast=fast->next;
        if(fast->next!=(*head1) ){
            fast=fast->next;
        }
    }
    *head2=slow->next;
    *tail2=fast;
    slow->next=*head1;
    (*tail2)->next=*head2;
    
}
int main() {
   node *head1=NULL;
   node *tail1=NULL;
   node *head2=NULL;
   node *tail2=NULL;
   int choice=0;
   printf("Enter 1: insert element in 1st linked list\n");
   printf("Enter -1 to Exit\n");
   while(choice!=-1){
       printf("Enter choice: ");
       scanf("%d",&choice);
       if(choice==1){
            int data;
           printf("Enter data: ");
           scanf("%d",&data);
           insertNode(data,&head1,&tail1);
       }
       else{
           break;
       }
   }
   print(head1);
   split(&head1,&tail2,&head2,&tail2);
   printf("First half\n");
   print(head1);
   printf("Second half\n");
   print(head2);
 

    return 0;
}