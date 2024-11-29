#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* CreateNode(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next=NULL;
    return newnode;
}

struct Node* PushNodeBeg(struct Node* head,int val){
    if(head==NULL){
        struct Node* new_node = CreateNode(val);
        head = new_node;
        head->next = NULL;
        free(new_node);
        return head;
    }

    if(head!=NULL){}
}

int main(){
    struct Node* head = NULL;

}