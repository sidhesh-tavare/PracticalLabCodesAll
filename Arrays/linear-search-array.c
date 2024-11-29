#include <stdio.h>
#include <stdlib.h>


int LinearSearch(int arr[] , int key){
    int size = sizeof(arr) / (arr[0]);
    for(int i = 0 ; i < size ; i++){
        if(key == arr[i])
            return i;
    }
    return -1;
}

int main(){
    printf("Enter Elements of the array : ");
    int arr[100],i=0;
    int input;

    while(1){
        scanf("%d",&input);
        if (input == -1)
            break;
        arr[i++]= input; 
    }

    printf("Entered array is : ");
    for(int j = 0 ; j < i ; j++)
        printf("%d ",arr[j] );
    
    int key;
    printf("Enter Key to be searched ");
    scanf("%d",&key);

    int res = LinearSearch(arr,key);
    if(res!=-1) printf("res");
    else printf("Not Found");

}