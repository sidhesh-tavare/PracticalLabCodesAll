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
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

struct Node* Enqueue(struct Node* head,int val){
    if(head==NULL){
        struct Node* newnode = CreateNode(val);
        head = newnode;
        head->next = NULL;
        return head;
    } 

    if(head!=NULL){
        struct Node* newnode = CreateNode(val);
        struct Node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next = NULL;
        return head;
    }
}

struct Node* Dequeue(struct Node* head){
    if(head==NULL){
        printf("Empty List");
        return head;
    }

    if(head->next==NULL){
        // only one node exist ie. head
        struct Node* temp = head;
        head = NULL;
        free(temp);
        return head;
    }

    if(head->next!=NULL){
        struct Node* temp = head;
        head=head->next;
        free(temp);
        return head;
    }

}

void display(struct Node* head){
    if(head==NULL) printf("Empty List");
    struct Node* temp = head;
    while(temp!=NULL){
        printf("%d >",temp->data);
        temp=temp->next;
    }
}

int main(){
    struct Node* head = NULL;
    head = Enqueue(head,10);
    head = Enqueue(head,20);
    head = Enqueue(head,30);
    head = Enqueue(head,40);
    head = Enqueue(head,50);
    printf("\n\n");
    display(head);
    printf("\n\n");
    head=Dequeue(head);
    printf("DELETE FROM beg");
    printf("\n\n");
    display(head);

    head = Enqueue(head,123);
}