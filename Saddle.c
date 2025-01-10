#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
int min(int value1,int value2){
    return value1>value2?value2:value1;
}
void solve(int **array,int nrow,int ncolumn){
    int minimum[nrow];
    for(int row=0;row<nrow;row++){
        int min_element=INT_MAX;
        for(int column=0;column<ncolumn;column++){
            min_element=min(min_element,array[row][column]);
        }
        minimum[row]=min_element;
    }
    for(int row=0;row<nrow;row++){
        printf("minimum:%d ",minimum[row]);
    }
    printf("\n");
    int row_index=0;
    bool issaddlePoint=false;
    for(int column=0;column<ncolumn;column++){
        int maximum=INT_MIN;
        for(int row=0;row<nrow;row++){
            if(array[row][column]>=maximum){
                maximum=array[row][column];
                row_index=row;
            }
        }
       if(maximum==minimum[row_index]){
           issaddlePoint=true;
           printf("%d\n",maximum);
       }
    }
    if(!issaddlePoint){
        printf("%d",-1);
    }
        
}
int main() {
    // Write C code here
    int nrow,ncolumn;
    printf("Enter number of row:");
    scanf("%d",&nrow);
    printf("Enter number of column:");
    scanf("%d",&ncolumn);
    int *array[nrow];
    for(int row=0;row<nrow;row++){
        array[row]=(int*)malloc(ncolumn*sizeof(int));
    }
    for(int row=0;row<nrow;row++){
        for(int column=0;column<ncolumn;column++){
            printf("Enter value for (%d,%d):",row,column);
            scanf("%d",&array[row][column]);
        }
    }
  solve(array,nrow,ncolumn);
    return 0;
}