// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
    int data;
    node *prev;
    node *next;
    node *child;
};
void insertNode(int value,node **head,node **tail){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=NULL;
    newNode->child=NULL;
    if(*head==NULL){
        *head=newNode;
        *tail=newNode;
        return;
    }
    (*tail)->next=newNode;
    newNode->prev=(*tail);
    *tail=newNode;
}
node *createNode(int value){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=NULL;
    newNode->child=NULL;
    return newNode;
}
void solve(node *head,node **head1,node **tail1){
    if(head==NULL){
        return;
    }
    insertNode(head->data,&(*head1),&(*tail1));
    if(head->child){
        solve(head->child,&(*head1),&(*tail1));
    }
    if(head->next){
        solve(head->next,&(*head1),&(*tail1));
    }
}
node *flatten(node *head){
   node *head1=NULL;
   node *tail1=NULL;
   solve(head,&head1,&tail1);
   return head1;
}
int main() {
   node *head=NULL;
   node *tail=NULL;
   head=createNode(5);
   head->next=createNode(6);
   head->next->prev=head;
   head->next->child=createNode(7);
   head->next->child->prev=head->next;
   head->next->next=createNode(9);
   head->next->next->prev=head->next->next;
   node *result=flatten(head);
   node *temp=result;
   while(temp!=NULL){
       printf("%d ",temp->data);
       temp=temp->next;
   }
  
  
   

    return 0;
}
