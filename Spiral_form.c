#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void spiral(int **arr,int N,int *ans){
   int count=0;
    int total=N*N;
    int srow=0;
    int lrow=N-1;
    int scol=0;
    int lcol=N-1;
    while(count<total){
        for(int col=scol;col<=lcol && count<total;col++){
            ans[count++]=arr[srow][col];
        }
        srow++;
        for(int row=srow;row<=lrow && count<total;row++){
            ans[count++]=arr[row][lcol];
        }
        lcol--;
        for(int col=lcol;col>=scol && count<total;col--){
            ans[count++]=arr[lrow][col];
        }
        lrow--;
        for(int row=lrow;row>=srow && count<total;row--){
            ans[count++]=arr[row][scol];
        }
        scol++;
    }
   
}
int main() {
   int N;
    printf("Enter value of row and col");
    scanf("%d",&N);
    int **arr=(int**)malloc(N*sizeof(int*));
    for(int i=0;i<N;i++){
        arr[i]=malloc(N*sizeof(int));
    }
    for(int row=0;row<N;row++){
        for(int col=0;col<N;col++){
            printf("enter %d %d",row,col);
            scanf("%d",&arr[row][col]);
        }
    }
    int *ans=(int*)malloc(N*N*sizeof(int));
    spiral(arr,N,ans);
    int total=N*N;
    for(int row=0;row<total;row++){
        printf("%d ",ans[row]);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}