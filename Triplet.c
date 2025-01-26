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
void solve(node **head1,node **tail1,node **head2,node **tail2,node **head3,node **tail3,int targetSum){
    node *temp1=*head1;
    node *temp2=*head2;
    node *temp3=*head3;
    while(temp1!=NULL){
         int sum=temp1->data;
         temp2=*head2;
        while(temp2!=NULL){
            int value=sum+temp2->data; 
            temp3=*head3;
             while(temp3!=NULL){
                 int value1=value+temp3->data;
              if((value1)==targetSum){
                  printf("%d->%d->%d\n",temp1->data,temp2->data,temp3->data);
              }
              temp3=temp3->next;
             }
             temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}
int main() {
    int choice=0;
    node *head1=NULL;
    node *tail1=NULL;
    node *head2=NULL;
    node *tail2=NULL;    
    node *head3=NULL;
    node *tail3=NULL;
    while(choice!=-1){
        int choice;
        printf("Enter choice:");
        scanf("%d",&choice);
        if(choice==1){
            int data;
            printf("Enter data:");
            scanf("%d",&data);
        insertNode(data,&head1,&tail1);
        }
        else if(choice==2){
               int data;
            printf("Enter data:");
            scanf("%d",&data);
        insertNode(data,&head2,&tail2);
        }
        else if(choice==3){
                int data;
            printf("Enter data:");
            scanf("%d",&data);
        insertNode(data,&head3,&tail3);
        }
        else{
            break;
        }
    }
    int targetSum;
    printf("Enter sum: ");
    scanf("%d",&targetSum);
solve(&head1,&tail1,&head2,&tail2,&head3,&tail3,targetSum);

    return 0;
}