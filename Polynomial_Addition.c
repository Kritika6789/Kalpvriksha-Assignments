#include <stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
    int data;
    int power;
    node *next;
};
void print(node **head,node **tail){
    node *temp=*head;
    while(temp->next!=NULL){
        printf("%dx%d + ",temp->data,temp->power);
        temp=temp->next;
    }
    printf("%dx%d",temp->data);
}
void insertNode(int value,int power1,node **head,node **tail){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=value;
    newNode->power=power1;
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
        *tail=newNode;
        return;
    }
    (*tail)->next=newNode;
    *tail=newNode;
}
void add(node **head1,node **tail1,node **head2,node **tail2,node **head3,node **tail3 ){
    node *temp1=*head1;
    while(temp1!=NULL){
        int sum=temp1->data;
        node *temp2=*head2;
        while(temp2!=NULL){
            if(temp1->power==temp2->power){
            sum+=temp2->data;
            }
            temp2=temp2->next;
        }
        insertNode(sum,temp1->power,&(*head3),&(*tail3));
        temp1=temp1->next;
    }
}
int main() {
     node *head1=NULL;
     node *tail1=NULL;
     node *head2=NULL;
     node *tail2=NULL;
     node *head3=NULL;
     node *tail3=NULL;
     int choice=0;
     printf("enter 1 to enter data for first list\n");
     printf("enter 2 to enetr data for second list\n");
     printf("enter -1 to exit\n");
     int value,position;
     while(choice!=-1){
         printf("Enter choice");
         scanf("%d",&choice);
         if(choice==1){
             printf("Enter Data: ");
             scanf("%d",&value);
             printf("Enter Power: ");
             scanf("%d",&position);
             insertNode(value,position,&head1,&tail1);
         }
         else if(choice==2){
             printf("Enter Data: ");
             scanf("%d",&value);
             printf("Enter Power: ");
             scanf("%d",&position);
             insertNode(value,position,&head2,&tail2);
         }
         else{
             break;
         }
     }

    //  insertNode(4,0,&head2,&tail2);
     add(&head1,&tail1,&head2,&tail2,&head3,&tail3);
     print(&head3,&tail3);
    return 0;
}
