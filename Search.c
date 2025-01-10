#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
void solve(int **array,int nrow,int ncolumn){
    int target;
    printf("Enter target value: ");
    scanf("%d",&target);
    int start=0;
    int end=ncolumn-1;
    int col_index=0;
    bool isfound=false;
    for(int row=0;row<nrow;row++){
        if(target>=array[row][start] && target<=array[row][end]){
        for(int column=0;column<ncolumn;column++){
            if(target==array[row][column]){
          printf("Element %d found in the matrix at %d row ,%d column",target,row+1,column+1);
          isfound=true;
          break;
            }
        }
      }
    }
    if(!isfound){
        printf("Element %d not found in the matrix",target);
    }
    
    
}
int main() {
    // Write C code here
    // printf("Try programiz.pro");
    int nrow,ncolumn;
    printf("Enter number of row: ");
    scanf("%d",&nrow);
    printf("Enter number of column: ");
    scanf("%d",&ncolumn);
    int *array[nrow];
    for(int row=0;row<nrow;row++){
        array[row]=(int*)malloc(ncolumn*sizeof(int));
    }
    for(int row=0;row<nrow;row++){
        for(int column=0;column<ncolumn;column++){
           printf("enter value for (%d,%d): ",row,column);
           scanf("%d",&array[row][column]);
        }
    }
    solve(array,nrow,ncolumn);
    return 0;
}