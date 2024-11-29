#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void PrintArray(int arr[],int size){
    int i;
    for(i =0; i < size ; i++){
        printf("%d ",arr[i]);
    }
}

void BubbleSort(int arr[],int size){
    for(int i = 0 ; i < size-1;i++){
        for(int j = 0 ; j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
    printf("\n Bubble Sorting ke baad : ");
    PrintArray(arr,size);
}

void InsertionSort(int arr[] , int size){
    for(int i = 1 ; i < size ;++i){
        int key = arr[i];
        int j = i - 1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }

    printf("\n Insertion Sorting ke baad : ");
    PrintArray(arr,size);
}

void SelectionSort(int arr[],int size){
    for(int i = 0 ; i < size-1;i++){
        int minx = 1;

        for(int j = i+1 ; j<size;j++){
            if (arr[j]<arr[minx]) minx=j;
        }
        int temp = arr[i];
        arr[i] = arr[minx];
        arr[minx] = temp;
    }
    printf("\n Selection Sorting ke baad : ");
    PrintArray(arr,size);
}


int main(){
    int arr[] = {12,43,122,32,90,16,98,45,67,823,1000};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("\n asli array : ");
    PrintArray(arr,size);

    BubbleSort(arr,size);

    InsertionSort(arr,size);

    SelectionSort(arr,size);
}   