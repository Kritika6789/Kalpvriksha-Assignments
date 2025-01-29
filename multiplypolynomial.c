// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node node;
struct node{
    int data;
    int power;
    node *next;
};
int max(int value1,int value2){
    return value1>value2?value1:value2;
}
void print(node **head,node **tail){
    node *temp=*head;
    while(temp!=NULL){
        if(temp->power>1){
        printf("%dx%d + ",temp->data,temp->power);
        }
        else if(temp->power==1){
            printf("%dx+ ",temp->data);
        }
        else{
            printf("%d",temp->data);
        }
        temp=temp->next;
    }
    printf("\n");
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
void evaluate(node **head,node **tail){
    node *temp=*head;
    int maxPower=INT_MIN;
    while(temp!=NULL){
        maxPower=max(maxPower,temp->power);
        temp=temp->next;
    }
    int *powerArray=(int*)malloc((maxPower+1)*sizeof(int));
    for(int i=0;i<maxPower;i++){
        powerArray[i]=0;
    }
    temp=*head;
    while(temp!=NULL){
        int power1=temp->power;
        powerArray[power1]+=temp->data;
        temp=temp->next;
    }
    *head=NULL;
    *tail=NULL;
    for(int i=maxPower;i>=0;i--){
       if(powerArray[i]>0){
           int value=powerArray[i];
           int power1=i;
           insertNode(value,power1,&(*head),&(*tail));
       }
    }
}

void multiply(node **head1,node **tail1,node **head2,node **tail2,node **head4,node **tail4){
    node *temp1=*head1;
    node *temp2=*head2;
    while(temp1!=NULL){
        while(temp2!=NULL){
            int multiply=temp1->data;
            int addpower=temp1->power;
            multiply*=temp2->data;
            addpower+=temp2->power;
  insertNode(multiply,addpower,&(*head4),&(*tail4));
  temp2=temp2->next;
      }
      temp2=*head2;
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
     node *head4=NULL;
     node *tail4=NULL;
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
 print(&head1,&tail1);
  print(&head2,&tail2);
     multiply(&head1,&tail1,&head2,&tail2,&head4,&tail4);
     evaluate(&head4,&tail4);
     print(&head4,&tail4);
    return 0;
}