#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int BinarySearch(int arr[], int key, int size){
    int low = 0;
    int high = size;

    while(low<=high){
        int mid = low + ( high - low)/2;

        if(arr[mid] == key) return mid;
        if(arr[mid] > key) high = mid -1;
        if(arr[mid] < key) low = mid+1;
    }
    return -1;
}

int main(){
    int arr[]={10,12,17,34,57,90,101,190,132};
    int key;
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Enter Key to be searched : ");
    scanf("%d",&key);

    int res = BinarySearch(arr,key,size);
    if(res==-1) printf("Element not Found in array");
    else printf("%d key found at %d position in array ( non 0 indexing )",key,res+1);

}

