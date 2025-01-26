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
void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int listLength(node *head){
    node *temp=head;
    int count=0;
    while(temp!=NULL){
       count++;
       temp=temp->next;
    }
    return count;
}
int power(int base,int exponent){
    int result=1;
    for(int index=1;index<=exponent;index++){
        result=result*2;
    }
    return result;
}
void solve(node **head1,node **tail1){
    int length=listLength(*head1);
    int sum=0;
    node *temp=*head1;
    while(temp!=NULL){
        if(temp->data==1){
            sum+=power(2,length-1);
        }
        length--;
         temp=temp->next;
    }
    printf("Decimal form: %d",sum);
   
}

int main() {
   node *head1=NULL;
   node *tail1=NULL;
  
   int choice=0;
   printf("Enter 1: insert element in 1st linked list\n");
   printf("Enter -1 to exit\n");
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
   printf("\n");
   solve(&head1,&tail1);


    return 0;
}