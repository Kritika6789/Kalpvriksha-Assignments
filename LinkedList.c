#include <stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
    int data;
    node *next;
};
node *head=NULL;
node *tail=NULL;
int lengthOfList=0;
void insertAtEnd(int value){
    node *newNode1=(node*)malloc(sizeof(node));
    newNode1->data=value;
    newNode1->next=NULL;
    lengthOfList++;
    if(head==NULL){
        head=newNode1;
        tail=newNode1;
        return;
    }
    tail->next=newNode1;
    tail=newNode1;
}
void insertAtBeginning(int value){
   
   node *newNode2=(node*)malloc(sizeof(node));
   newNode2->data=value;
   newNode2->next=NULL;
   lengthOfList++;
   if(head==NULL){
       head=newNode2;
       tail=newNode2;
       return;
   }
   newNode2->next=head;
   head=newNode2;
}
void insertAtPosition(int position,int value){
   
    if(position<=0 || position>lengthOfList){
        printf("Invalid Position\n");
    }
    else if(position==1){
        insertAtBeginning(value);
    }
    else if(position==(lengthOfList+1)){
        insertAtEnd(value);
    }
    else{
        node *newNode3=(node*)malloc(sizeof(node));
        newNode3->data=value;
        newNode3->next=NULL;
        int count=1;
        node *current=head;
        while(count<position-1){
            count++;
            current=current->next;
        }
        newNode3->next=current->next;
        current->next=newNode3;
         lengthOfList++;
    }
}
void display(){
    if(head==NULL){
        printf("Empty list\n");
        return;
    }
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    free(temp);
}
void updateAtPosition(int position,int newValue){
  
    if(position<=0 ||position>lengthOfList){
        printf("Invalid Position\n");
    }
    else{
        int count=1;
        node *current=head;
        while(count<position){
            count++;
            current=current->next;
        }
        if(current){
            current->data=newValue;
        }
        else{
            printf("Error\n");
        }
    }
    }
void deleteAtBeginning(){
       if(head==NULL){
           printf("Linked List is Empty\n");
           return;
       } 
       if(head->next==NULL){
           head=NULL;
           return;
       }
       node *temp=head;
       head=head->next;
       temp->next=NULL;
       free(temp);
    }
void deleteAtEnd(){
    if(head==NULL){
        printf("Linked list is empty\n");
        return;
    }
    if(head->next==NULL){
        head=NULL;
        return;
    }
    node *prev=NULL;
    node *current=head;
    while(current->next!=NULL){
        prev=current;
        current=current->next;
    }
    prev->next=NULL;
    free(current);
}
void deleteAtPosition(int position){
    if(head==NULL){
        printf("Linked list is empty\n");
        return;
    }

    if(head->next==NULL && position>1){
        printf("Invalid Position\n");
        return;
    }
    else if(position==1){
        deleteAtBeginning();
    }
    else if(position==lengthOfList){
        deleteAtEnd();
    }
    else if(position<=0 || position>lengthOfList){
        printf("Invalid Position\n");
        return;
    }
    else{
        int count=1;
        node *prev=NULL;
        node *current=head;
        while(count<position){
          prev=current;
          current=current->next;
          count++;
    }
        prev->next=current->next;
        current->next=NULL;
        free(current);
}
}
int main() {
    int number_of_operations;
    printf("Enter number of operations to perform: ");
    scanf("%d",&number_of_operations);
    if(number_of_operations<1|| number_of_operations>100){
        printf("1<=Number of operations<=100\n");
    }
    else{
    for(int operation=0;operation<number_of_operations;operation++){
     printf("1.Insert new node at End\n");
    printf("2.Insert new node at beginning\n");
    printf("3.Insert new node at position\n");
    printf("4.Display all node of Linked List\n");
    printf("5.Update in Linked List\n");
    printf("6.Delete node from beginning\n");
    printf("7.Delete node from end\n");
    printf("8.Delete node from particular position\n");
        int choice;
        printf("Enter choice:");
        scanf("%d",&choice);
        if(choice==1){
                int value1;
                   printf("Enter data:");
                   scanf("%d",&value1);
                   insertAtEnd(value1);
        }
        else if(choice==2){
                   int value2;
                   printf("Enter data:");
                   scanf("%d",&value2);
                   insertAtBeginning(value2);
        }
        else if(choice==3){
                   int position1;
                   printf("Enter position:");
                   scanf("%d",&position1);
                   int value3;
                   printf("Enter data:");
                   scanf("%d",&value3);
                   insertAtPosition(position1,value3);
                   }
            else if(choice==4){
                display();
            }
            else if(choice==5){
                  int position2;
                  printf("Enter position to be updated:");
                  scanf("%d",&position2);
                  int value4;
                  printf("Enter updated data:");
                  scanf("%d",&value4);
                  updateAtPosition(position2,value4);
            }
            else if(choice==6){deleteAtBeginning();
            }
            else if(choice==7){deleteAtEnd();
            }
            else if(choice==8){
                   int position3;
                   printf("Enter the position of node to be deleted:");
                   scanf("%d",&position3);
                   deleteAtPosition(position3);
            }
            else{
                   printf("Invalid Operation:\n");
            }
        
    }
    }
 

    return 0;
}
