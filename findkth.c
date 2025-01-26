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
    printf("\n");
}
int listlength(node *head){
    int count=0;
    node *temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void findKth(node **head,node **tail,int k){
    int length=listlength(*head);
    if(k>length){
        printf("Linked list length is less than k");
        return;
    }
    int index=length-k;
    node *temp=*head;
    int count=0;
    while(count<index){
        temp=temp->next;
        count++;
    }
    printf("%d",temp->data);
}
int main() {
    node *head1=NULL;
    node *tail1=NULL;
    int k;
    printf("Enter k:");
    scanf("%d",&k);
    int choice=-1;
    printf("Enter 1 to insert element in 1st linked list\n");
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
        else{
            break;
        }
    }
    print(head1);
    findKth(&head1,&tail1,k);
    

    return 0;
}