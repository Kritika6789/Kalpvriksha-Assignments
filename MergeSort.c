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
void mergeSort(node **head1,node **tail1,node **head2,node **tail2){
  node *head3=NULL;
  node *tail3=NULL;
  node *temp1=*head1;
  node *temp2=*head2;
  while(temp1!=NULL && temp2!=NULL){
      if(temp1->data<temp2->data){
           insertNode(temp1->data,&head3,&tail3);
           temp1=temp1->next;
      }
      else{
          insertNode(temp2->data,&head3,&tail3);
          temp2=temp2->next;
      }
  }
  while(temp1!=NULL){
      insertNode(temp1->data,&head3,&tail3);
      temp1=temp1->next;
  }
  while(temp2!=NULL){
      insertNode(temp2->data,&head3,&tail3);
      temp2=temp2->next;
  }
    *head1=head3;
    *tail1=tail3;
}
void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main() {
    node *head1=NULL;
    node *tail1=NULL;
    node *head2=NULL;
    node *tail2=NULL;
    int choice=-1;
    printf("Enter 1 to insert element in 1st linked list\n");
    printf("Enter 2 to insert element in 2nd linked list\n");
    printf("Enter -1 to exit\n");
    while(choice!=0){
        printf("Enter choice: ");
        scanf("%d",&choice);
        if(choice==1){
            int data;
            printf("Enter data: ");
            scanf("%d",&data);
            insertNode(data,&head1,&tail1);
        }
        else if(choice==2){
            int data;
            printf("Enter data:");
            scanf("%d",&data);
            insertNode(data,&head2,&tail2);
        }
        else{
            break;
        }
    }
    print(head1);
    print(head2);
    mergeSort(&head1,&tail1,&head2,&tail2);
    print(head1);
    

    return 0;
}