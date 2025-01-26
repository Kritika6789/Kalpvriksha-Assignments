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
void reverse(node **head,node **tail){
    node *prev=NULL;
    node *current=*head;
    node *Next=current->next;
    while(current!=NULL){
        Next=current->next;
        current->next=prev;
        prev=current;
        current=Next;
    }
    *tail=*head;
    *head=prev;
}
void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void add(node **head3,node **tail3,node **head4,node **tail4){
    node *head5=NULL;
    node *tail5=NULL;
    int sum=0;
    int carry=0;
    node *temp1=*head3;
    node *temp2=*head4;
    while(temp1!=NULL && temp2!=NULL){
        sum=temp1->data+temp2->data+carry;
        int value=sum%10;
        carry=sum/10;
        insertNode(value,&head5,&tail5);
        temp1=temp1->next;
        temp2=temp2->next;
    }
    while(temp1!=NULL){
        sum=temp1->data+carry;
         int value=sum%10;
        carry=sum/10;
        insertNode(value,&head5,&tail5);
        temp1=temp1->next;
    }
      while(temp2!=NULL){
        sum=temp2->data+carry;
         int value=sum%10;
        carry=sum/10;
        insertNode(value,&head5,&tail5);
        temp2=temp2->next;
    }
    if(carry==1){
        insertNode(1,&head5,&tail5);
    }
    *head4=head5;
    *tail4=tail5;
}
void multiply(node **head1,node **tail1,node **head2,node **tail2,node **head3,node **tail3,node **head4,node **tail4){
     node *temp1=*head1;
    node *temp2=*head2;
    int count=0;
    while(temp2!=NULL){
        int number=temp2->data;
        int carry=0;
        while(temp1!=NULL){
            int multiple=number*(temp1->data)+carry;
            int value=multiple%10;
            carry=multiple/10;
            insertNode(value,&(*head3),&(*tail3));
            temp1=temp1->next;
        } 
         if(carry==1){
             insertNode(1,&(*head3),&(*tail3));
             carry=0;
         }
           printf("before reversal answer:\n");
           print(*head3);
           printf("\n");
        reverse(&(*head3),&(*tail3));
        printf("after reversal answer:\n");
         print(*head3);
           printf("\n");
        int c=count;
        while(c!=0){
            printf("appended 0\n");
            insertNode(0,&(*head3),&(*tail3));
            c--;
        }
        printf("appende 0 result\n");
        print(*head3);
        printf("\n");
        if(count>0){
            printf("reverse head3:\n");
            reverse(&(*head3),&(*tail3));
             print(*head3);
           printf("\n");
           printf("reverse head4:\n");
            reverse(&(*head4),&(*tail4));
             print(*head4);
           printf("\n");
           printf("add:\n");
            add(&(*head3),&(*tail3),&(*head4),&(*tail4));
             print(*head4);
           printf("\n");
            reverse(&(*head4),&(*head4));
            printf("after reversal answer:\n");
             print(*head4);
           printf("\n");
           if(temp2->next==NULL){
               break;
           }
        }
         *head4=*head3;
         *tail4=*tail3;
        *head3=NULL;
        *tail3=NULL;
        temp1=*head1;
        count++;
        temp2=temp2->next;
    }
}

int main() {
   node *head1=NULL;
   node *tail1=NULL;
   node *head2=NULL;
   node *tail2=NULL;
   node *head3=NULL;
   node *tail3=NULL;
   node *head4=NULL;
   node *tail4=NULL;
   int choice=0;
   printf("Enter 1: insert element in 1st linked list\n");
   printf("Enter 2: insert element in 2nd linked list\n");
   while(choice!=-1){
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
           printf("Enter data: ");
           scanf("%d",&data);
           insertNode(data,&head2,&tail2);
       }
       else{
           break;
       }
   }
   print(head1);
   printf("\n");
   print(head2);
   printf("\n");
   multiply(&head1,&tail1,&head2,&tail2,&head3,&tail3,&head4,&tail4);
   print(head4);

    return 0;
}