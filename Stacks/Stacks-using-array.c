#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define MAX 10

struct Stack{
    int arr[MAX];
    in
    t top;
};

void createStack(struct Stack* stack){
    stack->top = -1;
}

bool isFull(struct Stack* stack){
    if(stack->top==MAX-1) return true;
    else return false;
}

bool isEmpty(struct Stack* stack){
    if(stack->top  == -1) return true;
    else return false;
}

void push(struct Stack* stack, int val){
    if(isFull(stack)) printf("Full");
    else{
        stack->arr[++stack->top] = val;
        printf("Pushed %d \n",val);
    }
}

int pop(struct Stack* stack){
    if(isEmpty(stack)) printf("Empty");
    else{
        int pop_val = stack->arr[stack->top--];
        printf("\nPopped %d",pop_val);
        return pop_val;
    }
}

int peek(struct Stack* stack){
    if (isEmpty(stack)) {printf("Empty");
    return -111;}

    else{
        int peek_val = stack->arr[stack->top];
        return peek_val;
    }
}

int main(){
    struct Stack stack;
    createStack(&stack);

    for(int i = 0 ; i< 7 ;i++){
        push(&stack,i);
    }

    printf("\nTop element is %d ",peek(&stack));
    pop(&stack);
    pop(&stack);

    if (isFull(&stack)) {
        printf("Stack is full\n");
    }

    printf("\nPeeking = %d",peek(&stack));


}