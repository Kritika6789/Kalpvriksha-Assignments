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
int listLength(node *head){
    int index=0;
    node *temp=head;
    while(temp!=NULL){
        index++;
        temp=temp->next;
    }
    return index;
}
void bubbleSort(node **start,node *end){
    node *temp1=*start;
    node *temp2=*start;
    while(temp1!=end){
        temp2=*start;
        while(temp2->next!=end){
            if(temp2->data>temp2->next->data){
                int temp=temp2->data;
                temp2->data=temp2->next->data;
                temp2->next->data=temp;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}
void sortList(node **head1,int number){
    node *start=NULL;
    node *end=NULL;
    node *temp=*head1;
    while(temp!=NULL){
    if((temp->data)%number==0){
        if(start==NULL){
            start=temp;
        }
    }
    else{
        if(end==NULL){
            end=temp;
            break;
        }
    }
    temp=temp->next;
    }
    if(start!=NULL){
        bubbleSort(&start,end);
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
node *find(node **head1){
    node *temp=*head1;
    while(temp!=NULL){
        if(((temp->data)%3)!=0 && ((temp->data)%5)!=0){
          return temp;
        }
        temp=temp->next;
    }
    return NULL;
}
void sort(node **head,node **head1,node **tail1,int length){
    node *visited[length];
    int index=0;
    node *temp=*head;
    while(temp!=NULL){
        visited[index++]=(node*)malloc(sizeof(node));
        temp=temp->next;
    }
    temp=*head;
    index=0;
    while(temp!=NULL){
        if(((temp->data)%3)==0){
            insertNode(temp->data,&(*head1),&(*tail1));
            visited[index++]=temp;
        }
        temp=temp->next;
    }
    temp=*head;
    while(temp!=NULL){
        if(((temp->data)%5)==0){
            bool isadded=false;
            for(int i=0;i<index;i++){
                if(visited[i]==temp){
                    isadded=true;
                    break;
                }
            }
            if(!isadded){
            insertNode(temp->data,&(*head1),&(*tail1));
            visited[index++]=temp;
            }
        }
        temp=temp->next;
    }
    temp=*head;
    while(temp!=NULL){
        bool isvisited=false;
        for(int i=0;i<index;i++){
            if(visited[i]==temp){
                isvisited=true;
                break;
            }
        }
        if(!isvisited){
            insertNode(temp->data,&(*head1),&(*tail1));
        }
        temp=temp->next;
    }

    sortList(&(*head1),3);
sortList(&(*head1),5);
 node *startNode=find(&(*head1));
   if(startNode !=NULL){
       bubbleSort(&(startNode),NULL);
   }
}

int main() {
    node *head=NULL;
    node *tail=NULL;
    int choice;
    while(1){
        printf("Enter Choice:");
        scanf("%d",&choice);
        if(choice==1){
            int data;
            printf("Enter data:");
            scanf("%d",&data);
            insertNode(data,&head,&tail);
        }
        else{
            break;
        }
    }
    int length=listLength(head);
    node *head1=NULL;
    node *tail1=NULL;
    sort(&head,&head1,&tail1,length);
    // node *result1=reverseK(head,k,length);
    print(head1);
    return 0;
}
