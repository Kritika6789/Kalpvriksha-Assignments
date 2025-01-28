// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
typedef struct node node;
struct node{
    int data;
    int power;
    node *next;
};

void print(node **head,node **tail){
    node *temp=*head;
    while(temp->next!=NULL){
            if(temp->power==1){
                 printf("%dx+",temp->data);
            }
            else if(temp->power>1){
            printf("%dx%d + ",temp->data,temp->power);
            }
            else{
                printf("%d + ",temp->data);
            }
            temp=temp->next;
        }
          if(temp->power==1){
                 printf("%dx",temp->data);
            }
            else if(temp->power>1){
            printf("%dx%d",temp->data,temp->power);
            }
            else{
                printf("%d",temp->data);
            }
            temp=temp->next;
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
int listLength(node **head){
    node *temp=*head;
    int index=0;
    while(temp!=NULL){
        index++;
        temp=temp->next;
    }
    return index;
}
int max(int value1,int value2){
    return value1>value2?value1:value2;
}
void add(node **head1,node **tail1,node **head2,node **tail2,node **head3,node **tail3 ){
    node *temp1=*head1;
    while(temp1!=NULL){
        int sum=temp1->data;
        node *temp4=*head3;
        bool isfound=false;
        while(temp4!=NULL){
            printf("enter");
            if(temp4->power==temp1->power){
                printf("found");
                temp4->data+=temp1->data;
                isfound=true;
                break;
            }
            temp4=temp4->next;
        }
        printf("\n");
        if(!isfound){
        node *temp2=*head2;
        while(temp2!=NULL){
            if(temp1->power==temp2->power){
            sum+=temp2->data;
            }
            temp2=temp2->next;
        }
        insertNode(sum,temp1->power,&(*head3),&(*tail3));
    }
    temp1=temp1->next;
    }
    int maxPower=INT_MIN;
    node *temp=*head1;
    while(temp!=NULL){
        int power1=temp->power;
        maxPower=max(maxPower,power1);
        temp=temp->next;
    }
    temp=*head2;
      while(temp!=NULL){
        int power1=temp->power;
        maxPower=max(maxPower,power1);
        temp=temp->next;
    }
    node *result[maxPower+1];
    for(int i=0;i<=maxPower;i++){
      result[i]=(node*)malloc(sizeof(node));
      result[i]=NULL;
    }
    
    node *temp3=*head3;
    while(temp3!=NULL){
        int index=temp3->power;
        result[index]=temp3;
        temp3=temp3->next;
    }
   temp3=*head2;
   while(temp3!=NULL){
       int power1=temp3->power;
       if(result[power1]==NULL){
           insertNode(temp3->data,temp3->power,&(*head3),&(*tail3));
           result[power1]=temp3;
       }
       temp3=temp3->next;
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
 print(&head1,&tail1);
  print(&head2,&tail2);
     add(&head1,&tail1,&head2,&tail2,&head3,&tail3);
     print(&head3,&tail3);
    return 0;
}
