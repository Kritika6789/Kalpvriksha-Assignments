#include<stdio.h>
#include<stdlib.h>
void access2(int **array,int nrow,int ncolumn){
    printf("2nd way to Access elements of 2D array:\n");
    for(int row=0;row<nrow;row++){
        for(int column=0;column<ncolumn;column++){
            printf("%d ",*(*(array+row)+column));
        }
        printf("\n");
    }
}
void access1(int **array,int nrow,int ncolumn){
    printf("1st way  to Acces using index:\n");
    for(int row=0;row<nrow;row++){
        for(int column=0;column<ncolumn;column++){
            printf("%d ",array[row][column]);
        }
        printf("\n");
    }
}
void access3(int **array,int row,int column){
    printf("3rd way of Accessing elements of array\n");
    for(int index1=0;index1<row;index1++){
        int *ptr=array[index1];
        for(int index2=0;index2<column;index2++){
            printf("%d ",*(ptr+index2));
        }
        printf("\n");
    }
}
void access4(int **array,int row,int column){
    printf("4th way of accessing elements of array\n");
    for(int index1=0;index1<row;index1++){
         for(int index2=0;index2<column;index2++){
             printf("%d ",*(array[index1]+index2));
         }
         printf("\n");
    }
}
void access5(int **array,int row,int column){
    printf("5th way of accessing elements\n");
    for(int index1=0;index1<row;index1++){
        int *ptr=array[index1];
        for(int index2=0;index2<column;index2++){
            printf("%d ",ptr[index2]);
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
    access3(array,nrow,ncolumn);
    access4(array,nrow,ncolumn);
    access5(array,nrow,ncolumn);
    return 0;
}
