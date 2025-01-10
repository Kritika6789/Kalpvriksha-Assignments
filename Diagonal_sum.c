// Online C compiler to run C program online
#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
void solve(int **array,int size){
    //diagonal 1
    // int sum=0;
    int ans[size*2];
    int index=0;
    for(int row=0;row<size;row++){
        int column=row;
         bool isexist=false;
        for(int index1=0;index1<index;index1++){
            if(ans[index1]==array[row][column]){
                isexist=true;
                break;
            }
        }
         if(!isexist){
            ans[index++]=array[row][column];
        }
    }
    for(int row=0;row<size;row++){
        int column=size-row-1;
        int value=array[row][column];
        bool isexist=false;
        for(int index1=0;index1<index;index1++){
            if(ans[index1]==value){
                isexist=true;
                break;
            }
        }
        if(!isexist){
            ans[index++]=value;
        }
    }
    int sum=0;
    for(int index3=0;index3<index;index3++){
        // printf("%d ",ans[index3]);
        sum+=ans[index3];
    }
    printf("\n");
    printf("sum:%d",sum);
    
}
int main() {
    int size;
    printf("Enter size:");
    scanf("%d",&size);
    int *array[size];
    for(int row=0;row<size;row++){
        array[row]=(int*)malloc(size*sizeof(int));
    }
    for(int row=0;row<size;row++){
        for(int column=0;column<size;column++){
            printf("Enter value for (%d %d): ",row,column);
            scanf("%d",&array[row][column]);
        }
    }
    // for(int row=0;row<size;row++)
    solve(array,size);

    return 0;
}