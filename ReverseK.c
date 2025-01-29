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
void reverse(node **array,int start,int end,int length){
    int startIndex=start;
    int endIndex=end;
    if(endIndex>=length){
        return;
    }
    while(startIndex<=endIndex){
       node *temp=array[startIndex];
       array[startIndex]=array[endIndex];
       array[endIndex]=temp;
       startIndex++;
       endIndex--;
    }
}
void reverseK(node **head,node **tail,int k){
    int length=listlength(*head);
    node *array[length];
    node *temp=*head;
    int index=0;
    while(temp!=NULL){
        array[index]=(node*)malloc(sizeof(node));
        array[index]=temp;
        index++;
        temp=temp->next;
    }
   for(int i=0;i<index;i+=k){
       int start=i;
       int end=i+k-1;
       reverse(array,start,end,length);
   }
   for(int i=0;i<index-1;i++){
       array[i]->next=array[i+1];
   }
   array[index-1]->next=NULL;
   *head=array[0];
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
    reverseK(&head1,&tail1,k);
    print(head1);
    

    return 0;
}