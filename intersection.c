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
node * intersection(node **head1,node **tail1,node **head2,node **tail2){
    node *temp1=*head1;
    node *temp2=*head2;
    while(temp1!=NULL){
        temp2=*head2;
        while(temp2!=NULL){
            if(temp1->data==temp2->data){
                return temp1;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return NULL;
}
int main() {
    node *head1=NULL;
    node *tail1=NULL;
    node *head2=NULL;
    node *tail2=NULL;
    int choice=0;
    while(choice!=-1){
        int choice;
        printf("enter choice: ");
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
        else{
            break;
        }
    }
   node *ans=intersection(&head1,&tail1,&head2,&tail2);
   if(ans==NULL){
       printf("no intersection point exist");
   }
   else{
       printf("%d",ans->data);
   }
    return 0;
}