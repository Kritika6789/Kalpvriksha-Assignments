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
int max(int value1,int value2){
    return value1>value2?value1:value2;
}
void solve(node **head1,node **tail1,node **head2,node **tail2){
  int length1=listLength(*head1);
  int length2=listLength(*head2);
  int list1[length1];
  int list2[length2];
  node *temp=*head1;
  int index=0;
  while(temp!=NULL){
      list1[index++]=temp->data;
      temp=temp->next;
  }
  int index1=0;
  temp=*head2;
  while(temp!=NULL){
      list2[index1++]=temp->data;
      temp=temp->next;
  }
  int index3=index-1;
  int index4=index1-1;
  int sum=0;
  int carry=0;
  int length=max(index,index1);
  node *list3[length+1];
  int index2=0;
  while(index3>=0 && index4>=0){
      sum=list1[index3]+list2[index4]+carry;
      int value=sum%10;
      carry=sum/10;
      list3[index2]=(node*)malloc(sizeof(node));
      list3[index2]->data=value;
      list3[index2]->next=NULL;
      index2++;
      index3--;
      index4--;
  }
  while(index3>=0){
        sum=list1[index3]+carry;
      int value=sum%10;
      carry=sum/10;
      list3[index2]=(node*)malloc(sizeof(node));
      list3[index2]->data=value;
      list3[index2]->next=NULL;
      index2++;
      index3--;
  }
    while(index4>=0){
        sum=list2[index4]+carry;
      int value=sum%10;
      carry=sum/10;
      list3[index2]=(node*)malloc(sizeof(node));
      list3[index2]->data=value;
      list3[index2]->next=NULL;
      index2++;
      index4--;
  }
  if(carry==1){
      list3[index2]=(node*)malloc(sizeof(node));
      list3[index2]->data=1;
      list3[index2]->next=NULL;
      index2++;
      carry=0;
  }
  for(int i=index2-1;i>0;i--){
      list3[i]->next=list3[i-1];
  }
  list3[0]->next=NULL;
  *head1=list3[index2-1];
}

int main() {
   node *head1=NULL;
   node *tail1=NULL;
   node *head2=NULL;
   node *tail2=NULL;
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
   solve(&head1,&tail1,&head2,&tail2);
   print(head1);

    return 0;
}