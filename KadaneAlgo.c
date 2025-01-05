#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int max(int value1,int value2){
    return value1>value2?value1:value2;
}
int maxValue(int *array,int length){
    int ans=INT_MIN;
    for(int index=0;index<length;index++){
      ans=max(ans,array[index]);
    }
    return ans;
}
int subsequence(int *array,int length){
    int maxElement=maxValue(array,length);
    if(maxElement<0){
        return maxElement;
    }
    int sum=0;
    for(int index=0;index<length;index++){
     if(array[index]>0){
        sum+=array[index];
     }
    }
    return sum;
}
int kadaneAlgo(int *array,int length){
    int result=array[0];
    int maxEnding=array[0];
    for(int index=1;index<length;index++){
        maxEnding=(maxEnding+array[index])>array[index]?(maxEnding+array[index]):array[index];
        result=max(result,maxEnding);
    }
    return result;
}
int main(){
    //finding maximum subsequence sum and maximum subarray sum in o(n) time complexity
    int length;
    printf("Enter length of array:");
    scanf("%d",&length);
    int *array=(int*)malloc(length*(sizeof(int)));
    for(int index=0;index<length;index++){
        printf("Enter %d element:",index+1);
        scanf("%d",&array[index]);
    }
    int maxSumSubsequence=subsequence(array,length);
    int maxSumSubarray=kadaneAlgo(array,length);
    printf("Maximum sum in subsequence of array:%d\n",maxSumSubsequence);
    printf("Maximum sum in subarray of array:%d",maxSumSubarray);
    return 0;
}