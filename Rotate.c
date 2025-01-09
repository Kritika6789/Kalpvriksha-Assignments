// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
void reverse(int *ans,int end){
    int start=0;
    while(start<end){
        int temp=ans[start];
        ans[start]=ans[end];
        ans[end]=temp;
        start++;
        end--;
    }
}
void solve(int **array,int nrow,int ncolumn){
    for(int row=0;row<nrow;row++){
        for(int column=row;column<ncolumn;column++){
            int temp=array[row][column];
            array[row][column]=array[column][row];
            array[column][row]=temp;
        }
    }
      for(int row=0;row<nrow;row++){
       for(int column=0;column<ncolumn;column++){
           printf("%d ",array[row][column]);
       }
       printf("\n");
   }
   printf("\n");
   for(int row=0;row<nrow;row++){
      reverse(array[row],ncolumn-1);
   }
   for(int row=0;row<nrow;row++){
       for(int column=0;column<ncolumn;column++){
           printf("%d ",array[row][column]);
       }
       printf("\n");
   }
}
int main() {
    // Write C code here
    // printf("Try programiz.pro");
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