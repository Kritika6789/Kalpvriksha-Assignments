#include<stdio.h>
#include<stdlib.h>
void access2(int **array,int nrow,int ncolumn){
    printf("Acces using pointer:\n");
    for(int row=0;row<nrow;row++){
        for(int column=0;column<ncolumn;column++){
            printf("%d ",*(*(array+row)+column));
        }
        printf("\n");
    }
}
void access1(int **array,int nrow,int ncolumn){
    printf("Acces using index:\n");
    for(int row=0;row<nrow;row++){
        for(int column=0;column<ncolumn;column++){
            printf("%d ",array[row][column]);
        }
        printf("\n");
    }
}
int main(){
    int nrow,ncolumn;
    printf("Enter row:");
    scanf("%d",&nrow);
    printf("Enter column:");
    scanf("%d",&ncolumn);
    int **array=(int**)malloc(nrow*sizeof(int*));
    for(int row=0;row<nrow;row++){
        array[row]=(int*)malloc(ncolumn*sizeof(int));
    }
    for(int row=0;row<nrow;row++){
        for(int column=0;column<ncolumn;column++){
            printf("Enter elements for (%d, %d):",row,column);
            scanf("%d",&array[row][column]);
        }
    }
    access1(array,nrow,ncolumn);
    access2(array,nrow,ncolumn);
    return 0;
}