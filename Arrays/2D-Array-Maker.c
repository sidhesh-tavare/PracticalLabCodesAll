#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define MAX 15
#define MIN 7

void PrintArray(int *arr, int rows, int cols){
    for(int i = 0 ; i < rows ; i++){
        printf("\n");
        for(int j = 0 ; j<cols;j++){
            printf("%d ", *(arr + i * cols + j));
        }
    }
}

int main(){
    
    int rows,cols;
    printf("Enter Number of rows : ");
    scanf("%d",&rows);
    printf("Enter Number of cols : ");
    scanf("%d",&cols);
    int arr[rows][cols];
    int max = 9,min = 5;
    
    for(int i = 0 ; i < rows ; i++){
        for(int j =0 ; j < cols ;j++){
            arr[i][j] = (rand()%(max-min+1)) + min;
        }
    }

    PrintArray(*arr,rows,cols);
}