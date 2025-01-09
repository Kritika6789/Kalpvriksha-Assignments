#include <stdio.h>
#include<stdlib.h>
void solve(int **array,int nrow,int ncolumn){
    int frequency[101]={0};
    for(int row=0;row<nrow;row++){
        for(int column=0;column<ncolumn;column++){
            int value=*(*(array+row)+column);
            frequency[value]++;
        }
    }
    printf("Frequency of each number:\n");
    for(int index=1;index<=100;index++){
        if(*(frequency+index)>0){
            printf("%d -> %d times\n",index,*(frequency+index));
        }
    }
}
int main() {
    int nrow;
    printf("Enter number of row:");
    scanf("%d",&nrow);
    printf("Enter number of column:");
    int ncolumn;
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
    for(int row=0;row<nrow;row++){
        for(int column=0;column<ncolumn;column++){
            printf("%d ",*(*(array+row)+column));
        }
        printf("\n");
    }
    solve(array,nrow,ncolumn);

    return 0;
}