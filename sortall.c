// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
void bubbleSort(node **head,node **tail){
   node *temp1=*head;
   node *temp2=*head;
   while(temp1!=NULL){
       temp2=*head;
       while(temp2->next!=NULL){
           if(temp2->data>temp2->next->data){
              int dataue=temp2->data;
              temp2->data=temp2->next->data;
              temp2->next->data=dataue;
           }
           temp2=temp2->next;
       }
       temp1=temp1->next;
   }
}
void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void insertSort(node **sorted,node **current){
    if(*sorted==NULL ||(*current)->data>=(*sorted)->data){
         (*current)->next=*sorted;
         *sorted=*current;
    }
    else{
      node *prev=NULL;
      node *temp=*sorted;
      while(temp!=NULL && (*current)->data<temp->data){
         prev=temp;
         temp=temp->next;
      }
    prev->next=*current;
    (*current)->next=temp;
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
void insertionSortList(node** head) {
    node *sorted=NULL;
    node* current=*head;
    node* Next=current->next;
    while(current!=NULL){
      Next=current->next;
     insertSort(&sorted,&current);
     current=Next;
    }
    reverse(&sorted);
    *head= sorted;
}
void selectionSort(node **head){
    node *temp1=*head;
    node *temp2=temp1->next;
    while(temp1!=NULL){
        temp2=temp1->next;
        int minivalue=temp1->data;
        node *minimum=temp1;
        while(temp2!=NULL){
            if(temp2->data<minivalue){
                minivalue=temp2->data;
                minimum=temp2;
            }
            temp2=temp2->next;
        }
        if(minimum!=temp1){
            int temp=temp1->data;
            temp1->data=minimum->data;
            minimum->data=temp;
        }
        temp1=temp1->next;
    }
}
int listlength(node *head){
    printf("length call");
    int index=0;
    node *temp=head;
    while(temp!=NULL){
        index++;
        temp=temp->next;
    }
    printf("length:%d",index);
    return index;
}
void swap(int *value1,int *value2){
    int temp=*value1;
    *value1=*value2;
    *value2=temp;
}
int partition(node **result,int start,int end){
    int pivot=result[start]->data;
    int count=0;
    for(int i=start+1;i<=end;i++){
        if(pivot>=result[i]->data){
            count++;
        }
    }
int pivotIndex=count+start;
swap(&(result[start]->data),&(result[pivotIndex]->data));
int i=start;
int j=end;
while(i<pivotIndex && j>pivotIndex){
    while(i<pivotIndex && result[i]->data<=pivot){
        i++;
    }
    while(j>pivotIndex && result[j]->data>pivot){
        j--;
    }
    if(i<pivotIndex && j>pivotIndex){
        swap(&(result[i]->data),&(result[j]->data));
        i++;
        j--;
    }
}
return pivotIndex;
}
void quickSort(node **result,int start,int end){
    if(start>=end){
        return;
    }
    int pivotIndex=partition(result,start,end);
    quickSort(result,start,pivotIndex-1);
    quickSort(result,pivotIndex+1,end);
}
void solve(node **head,node **tail){
    printf("Enter");
     int length=listlength(*head);
     printf("length:%d",length);
     node *result[length];
     node *temp=*head;
     int index=0;
     while(temp!=NULL){
         result[index]=(node*)malloc(sizeof(node));
         result[index]=temp;
         index++;
         temp=temp->next;
     }
     printf("before quicksort\n");
     for(int i=0;i<index;i++){
         printf("%d ",result[i]->data);
     }
     printf("\n");
     quickSort(result,0,index-1);
     printf("after quick sort\n");
       for(int i=0;i<index;i++){
         printf("%d ",result[i]->data);
     }
     printf("\n");
     for(int i=0;i<index-1;i++){
         result[i]->next=result[i+1];
     }
     result[index-1]->next=NULL;
     *head=result[0];
}
node* split(node *head){
    if(head==NULL){
        return head;
    }
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(fast){
            fast=fast->next;
        }
    }
    node *temp=slow->next;
    slow->next=NULL;
    return temp;
}

node *merge(node *first,node *second){
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    if(first->data<=second->data){
        first->next=merge(first->next,second);
        return first;
    }
    else{
        second->next=merge(first,second->next);
        return second;
    }
}
node* mergeSort(node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    print(head);
    node *second=split(head);
    head=mergeSort(head);
    second=mergeSort(second);
    return merge(head,second);
}
bool linearSearch(node *head,int target){
    node *temp=head;
    while(temp!=NULL){
        if(temp->data==target){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
bool binarySearch(node *head,int target){
    if(head==NULL){
         return false;
    }
     if(head->data==target){
        return true;
    }
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
    }
    node *temp=slow->next;
    slow->next=NULL;
    if(slow->data==target){
        printf("enter");
        return true;
    }
    else if((slow->data)>target){
        return binarySearch(head,target);
    }
    else{
        return binarySearch(temp,target);
    }
}
int main() {
    int choice=0;
    node *head1=NULL;
    node *tail1=NULL;
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
        else{
            break;
        }
    }
print(head1);
// print(head2);
// printf("Insertion Sort:\n");
// insertionSortList(&head1);
// print(head1);
// printf("Bubble sort:\n");
// bubbleSort(&head1,&tail1);
// print(head1);
// printf("selection sort\n");
// selectionSort(&head1);
// print(head1);
// printf("Quicksort\n");
// solve(&head1,&tail1);
// print(head1);
printf("MergeSort\n");
node *result=mergeSort(head1);
print(result);
int target;
printf("Enter target:");
scanf("%d",&target);
// if(linearSearch(head1,target)){
//     printf("Element found");
// }
// else{
//     printf("Element not found");
// }
if(binarySearch(head1,target)){
     printf("Element found");
}
else{
    printf("Element not found");
}

    return 0;
}