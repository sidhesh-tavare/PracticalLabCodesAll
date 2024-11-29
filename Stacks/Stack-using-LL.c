#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* push(struct Node* top, int val){
    
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode == NULL){
        printf("Stack Underflow");
        return top;
    }
    newnode->data = val;
    newnode->next = top;
    top = newnode;
    printf("\n%d pushed into stack",val);
    return top;
}

struct Node* pop(struct Node* top){
    struct Node* temp = top;
    int pop = temp->data;
    printf("\n%d popped from stack",temp->data);
    top=top->next;
    free(temp);
    return top;
}

void peek(struct Node* top){
    if(top==NULL) printf("Empty Stack");
    printf("\nTop element is : %d",top->data);
}

void display(struct Node* top){
    printf("\n");
    if (top==NULL)
    {printf("Empty Stack");
    return;}

    struct Node* temp = top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");}
    

int main(){
    struct Node* top = NULL;
    top=push(top,10);
    top = push(top,20);
    top = push(top,30);
    top = push(top,40);

    display(top);
    peek(top);
    top = pop(top);
    display(top);

}

