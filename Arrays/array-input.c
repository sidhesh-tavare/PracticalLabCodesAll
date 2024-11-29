#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[100],i=0;
    int input;

    while(1){
        scanf("%d",&input);
        if (input == -1)
            break;
        arr[i++]= input; 
    }

    for(int j = 0 ; j < i ; j++)
        printf("%d ",arr[j] );
}




