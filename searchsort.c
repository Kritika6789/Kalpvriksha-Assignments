// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
void insertSort(int *array,int length){
    for(int index=1;index<length;index++){
        int key=array[index];
        int sortedIndex=index-1;
        while(sortedIndex>=0 && key<array[sortedIndex]){
            array[sortedIndex+1]=array[sortedIndex];
            sortedIndex--;
        }
        array[sortedIndex+1]=key;
    }
}
void swap(int *value1,int *value2){
    int temp=*value1;
    *value1=*value2;
    *value2=temp;
}

void selectionSort(int *array,int length){
    for(int index=0;index<length;index++){
        int minimum=array[index];
        int min_index=index;
        for(int index1=index+1;index1<length;index1++){
            if(array[index1]<minimum){
                minimum=array[index1];
                min_index=index1;
            }
        }
        if(min_index!=index){
            swap(&array[index],&array[min_index]);
        }
    }
}
int partition(int *array,int start,int end){
    int pivot=array[start];
    int count=0;
    for(int index=start+1;index<=end;index++){
        if(pivot>=array[index]){
            count++;
        }
    }
    int pivotIndex=count+start;
    swap(&array[start],&array[pivotIndex]);
    int startIndex=start;
    int endIndex=end;
    while(startIndex<pivotIndex && endIndex>pivotIndex){
        while(startIndex<pivotIndex && array[startIndex]<=pivot){
            startIndex++;
        }
        while(endIndex>pivotIndex && array[endIndex]>pivot){
            endIndex--;
        }
        if(startIndex<pivotIndex && endIndex>pivotIndex){
            swap(&array[startIndex],&array[endIndex]);
            startIndex++;
            endIndex--;
        }
    }
    return pivotIndex;
}
void quickSort(int *array,int start,int end){
    if(start>=end){
        return;
    }
    int pivotIndex=partition(array,start,end);
    quickSort(array,start,pivotIndex-1);
    quickSort(array,pivotIndex+1,end);
}
void bubbleSort(int *array,int size){
    for(int pass=0;pass<size-1;pass++){
        for(int index=0;index<size-pass-1;index++){
            if(array[index]>array[index+1]){
                swap(&array[index],&array[index+1]);
            }
        }
    }
}
void merge(int *array,int start,int end){
    int mid=start+(end-start)/2;
    int startIndex=start;
    int endIndex=mid+1;
    int length=end-start+1;
    int *result=(int*)malloc(length*sizeof(int));
    int index=0;
    while(startIndex<=mid && endIndex<=end){
        if(array[startIndex]<=array[endIndex]){
            result[index++]=array[startIndex];
            startIndex++;
        }
        else{
            result[index++]=array[endIndex];
            endIndex++;
        }
    }
    while(startIndex<=mid){
        result[index++]=array[startIndex];
        startIndex++;
    }
    while(endIndex<=end){
        result[index++]=array[endIndex];
        endIndex++;
    }
    for(int index1=0;index1<index;index1++){
        array[index1+start]=result[index1];
    }
}
void mergeSort(int *array,int start,int end){
    if(start>=end){
        return;
    }
    int mid=start+(end-start)/2;
    mergeSort(array,start,mid);
    mergeSort(array,mid+1,end);
    merge(array,start,end);
}
void linearSearch(int *array,int size){
    int foundIndex=-1;
    int target;
    printf("Enter targer element: ");
    scanf("%d",&target);
    for(int index=0;index<size;index++){
        if(array[index]==target){
            foundIndex=index;
            break;
        }
    }
   if(foundIndex!=-1){
       printf("Element found at index %d",foundIndex);
   }
   else{
       printf("Element not found!");
   }
}
int binarySearch(int *array,int start,int end,int target){
   if(start>end){
       return -1;
   } 
   int mid=start+(end-start)/2;
   if(array[mid]==target){
       return mid;
   }
   else if(array[mid]>target){
       return binarySearch(array,start,mid-1,target);
   }
   else{
       return binarySearch(array,mid+1,end,target);
   }
}
void search(int *array,int size){
    mergeSort(array,0,size-1);
    int target;
    printf("Enter element:");
    scanf("%d",&target);
    int start=0;
    int end=size-1;
    int foundIndex=binarySearch(array,start,end,target);
    if(foundIndex!=-1){
       printf("Element found at index %d",foundIndex);
   }
   else{
       printf("Element not found!");
   }
}
void print(int *array,int length){
    for(int index=0;index<length;index++){
        printf("%d ",array[index]);
    }
    printf("\n");
}
int main() {
     int size;
     printf("Enter size:");
     scanf("%d",&size);
     int *array=(int*)malloc(size*sizeof(int));
     for(int index=0;index<size;index++){
         printf("Enter element: ");
         scanf("%d",&array[index]);
     }
     print(array,size);
     printf("Enter 1 to implement Insertion Sort\n");
     printf("Enter 2 to implment Selection Sort\n");
     printf("Enter 3 to implement Quick Sort\n");
     printf("Enter 4 to implement Merge Sort\n");
     printf("Enter 5 to implement Bubble sort\n ");
     printf("Enter 6 to implement Linear Search\n");
     printf("Enter 7 to implement Binary Search\n");
    int choice;
    printf("Enter choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:insertSort(array,size);
               print(array,size);
        break;
        case 2:selectionSort(array,size);
               print(array,size);
        break;
        case 3:quickSort(array,0,size-1);
               print(array,size);
        break;
        case 4:mergeSort(array,0,size-1);
               print(array,size);
        break;
        case 5:bubbleSort(array,size);
               print(array,size);
        break;
        case 6:linearSearch(array,size);
        break;
        case 7:search(array,size);
        break;
        default:
        printf("Invalid choice");
        break;
    }

    return 0;
}