// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct stack stack;
struct stack{
    int top;
    int capacity;
    int *array;
};
bool isEmpty(stack *s){
    if(s->top==-1){
        return true;
    }
    return false;
}
bool isFull(stack *s){
    int size=s->capacity;
    if(s->top==(size-1)){
        return true;
    }
    return false;
}
void push(stack **s){
    if(isFull(*s)){
        printf("stack overflow\n");
        return;
    }
    int value;
    printf("enter data:");
    scanf("%d",&value);
    (*s)->top=(*s)->top+1;
    int index=(*s)->top;
    (*s)->array[index]=value;
}
void pop(stack **s){
    if(isEmpty(*s)){
        printf("stack underflow\n");
        return;
    }
    int index=(*s)->top;
    (*s)->array[index]=-1;
     (*s)->top=(*s)->top-1;
}
void peek(stack **s){
    if((*s)->top==-1){
        printf("Empty Stack");
        return;
    }
    int index=(*s)->top;
    printf("stack top: %d\n",(*s)->array[index]);
}
void print(stack **s){
    int length=(*s)->top;
    for(int index=length;index>=0;index--){
        printf("%d ",(*s)->array[index]);
    }
    printf("\n");
}
void sizeOfStack(stack **s){
    printf("size:%d\n",((*s)->top)+1);
    return;
}
int main() {
    int size;
    printf("Enter capacity:");
    scanf("%d",&size);
    stack *st=(stack*)malloc(sizeof(stack));
    st->capacity=size;
    st->top=-1;
    st->array=(int*)malloc(size *sizeof(stack));
    int choice=-1;
    printf("Enter 1:Push\n");
    printf("Enter 2:Pop\n");
    printf("Enter 3:Peek\n");
    printf("Enter 4:isEmpty\n");
    printf("Enter 5:isFull\n");
    printf("Enter 6:print\n");
    printf("Enter 7:size\n");
    printf("Enter 8:Exit\n");
    while(1){
        printf("Enter choice");
        scanf("%d",&choice);
        if(choice==1){
            push(&st);
        }
        else if(choice==2){
            pop(&st);
        }
        else if(choice==3){
            peek(&st);
        }
        else if(choice==4){
            if(isEmpty(st)){
                printf("stack is empty");
            }
            else{
                printf("not empty");
            }
        }
        else if(choice==5){
            if(isFull(st)){
                printf("stack full");
            }
            else{
                printf("not full");
            }
        }
        else if(choice==6){
            print(&st);
        }
        else if(choice==7){
            sizeOfStack(&st);
        }
        else{
            break;
        }
    }
    
    return 0;
}
