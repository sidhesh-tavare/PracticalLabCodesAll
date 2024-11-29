#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void PrintArray(int arr[],int size){
    int i;
    for(i =0; i < size ; i++){
        printf("%d ",arr[i]);
    }
}

void swap(int*a,int*b){
    int temp =*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low ; j<high;j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main(){
    int arr[] = {12,43,122,32,90,16,98,45,67,823,1000};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("\n asli array : ");
    PrintArray(arr,size);
    quicksort(arr,0,size-1);

    printf("\nArray after QuickSort: ");
    PrintArray(arr, size);
    return 0;
}