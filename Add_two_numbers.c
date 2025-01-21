// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node node;
struct node{
    int data;
    node *next;
};
void insertAtEnd(node **head1,node **tail1,int value){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=value;
    newNode->next=NULL;
    if(*head1==NULL){
        *head1=newNode;
        *tail1=newNode;
        return;
    }
    (*tail1)->next=newNode;
    (*tail1)=newNode;
}
void print(node **head){
    node *temp=*head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
}
void reverse(node **head){
    node *prev=NULL;
    node *current=*head;
    node *Next=current->next;
    while(current!=NULL){
        Next=current->next;
        current->next=prev;
        prev=current;
        current=Next;
    }
    *head=prev;
}
void sum(node **head1,node **head2,node **head3,node **tail3){
    node *temp1=*head1;
    node *temp2=*head2;
    int carry=0;
    while(temp1!=NULL && temp2!=NULL){
        int sum=temp1->data+temp2->data+carry;
        int value=sum%10;
        carry=sum/10;
        insertAtEnd(head3,tail3,value);
        temp1=temp1->next;
        temp2=temp2->next;
    }
    while(temp1!=NULL){
        int sum=temp1->data+carry;
        int value=sum%10;
        carry=sum/10;
        insertAtEnd(head3,tail3,value);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
         int sum=temp2->data+carry;
        int value=sum%10;
        carry=sum/10;
        insertAtEnd(head3,tail3,value);
        temp2=temp2->next;
    }
    if(carry==1){
        insertAtEnd(head3,tail3,1);
    }
    
}
int main() {
    node *head1=NULL;
    node *tail1=NULL;
    node *head2=NULL;
    node *tail2=NULL;
    node *head3=NULL;
    node *tail3=NULL;
    char *ans=(char*)malloc(100*sizeof(char));
    printf("Enter string");
    scanf("%s",ans);
    int length=strlen(ans);
    for(int i=0;i<length;i++){
        int value=ans[i]-'0';
        insertAtEnd(&head1,&tail1,value);
    }
     char *ans2=(char*)malloc(100*sizeof(char));
    printf("Enter string");
    scanf("%s",ans2);
    int length1=strlen(ans2);
    for(int i=0;i<length1;i++){
        int value=ans2[i]-'0';
        insertAtEnd(&head2,&tail2,value);
    }
    print(&head1);
    printf("\n");
    print(&head2);
     printf("\n");
    reverse(&head1);
    reverse(&head2);
    sum(&head1,&head2,&head3,&tail3);
    reverse(&head3);
     printf("\n");
    print(&head3);

    return 0;
}
