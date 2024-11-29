#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* newnode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    return temp; 
}

void traversal(struct Node* head)
{
    struct Node* current = head;
    printf("\n");
    while(current!=NULL){
        printf("%d >",current->data);
        current=current->next;
    }
    printf("NULL");
    printf("\n");
}

bool searchLL(struct Node* head,int target){
    while (head != NULL){
        if(head->data == target) return true;
        head=head->next;
    }
    return false;
}

int findlengthofLL(struct Node* head){
    int length = 0;
    while(head!=NULL){
        length++;
        head=head->next;
    }
    return length;
}

struct Node* InsertBeg(struct Node* head, int val){
    struct Node* new_node = newnode(val);
    new_node->next = head;
    head = new_node;
    return head;
}

struct Node* InsertEnd(struct Node* head, int val){
    struct Node* new_node = newnode(val);

    struct Node* curr = head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next = new_node;
    new_node->next = NULL;
    return head;
}

struct Node* InsertatPos(struct Node* head, int val , int pos){
    if(pos<1){
        printf("Invalid Position ");
        return head;
    }

    //Insert at beginning ie. pos = 1
    if(pos==1){
        struct Node* new_node = newnode(val);
        new_node->next = head;
        head=new_node;
        return head;
    }

    struct Node* curr = head;
    int count = 1;
    while(count < pos-1 && curr!=NULL){
        curr=curr->next;
        count++;
    }
    if (curr==NULL){
        printf("Invalid Position\n");
        return head;
    }

    struct Node* new_node = newnode(val);
    new_node->next = curr->next;
    curr->next = new_node;
    return head;
}

struct Node* Delete_at_Beg(struct Node* head){
    if(head==NULL) return NULL;
    struct Node* temp = head;
    head= head->next;
    free(temp);
    return head;
}

struct Node* Delete_at_End(struct Node* head){
    if(head== NULL){
        printf("empty List");
        return head;
    }

    if (head->next == NULL){
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node* Delete_at_Pos(struct Node* head,int pos){
    if(head==NULL || pos<1){
        return head;
    }

    if(pos == 1){
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* curr = head;
    for(int i = 1 ; i < pos -1 && curr!=NULL ; i++){
        curr=curr->next;
    }

    if (curr == NULL || curr->next == NULL){
        return head;
    }

    struct Node* temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
    return head;
}

struct Node* PrintAll(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL) {
    printf("%d-> ", temp->data);
    temp = temp->next;
}
    return head;
}

int main(){
    struct Node* head = NULL;

    head = InsertBeg(head,10);
    head = InsertBeg(head,20);
    head = InsertBeg(head,30);

    printf("After Inserting at beg we get : \n");
    traversal(head);

    printf("After Inserting at end we get : \n");
    traversal(head);
    head= InsertEnd(head,40);
    head= InsertEnd(head,50);
    
    printf("Inserting at end LL = ");
    traversal(head);

    head = InsertatPos(head,25,2);
    traversal(head);

    int target = 400;
    if(searchLL(head,target)) printf("Found in LL \n");
    else printf("Not Found Bhratashree !");
    
    target = 40;
    if(searchLL(head,target)) printf("Found in LL \n");
    else printf("Not Found Bhratashree !");

    int len = findlengthofLL(head);
    printf("\nYour LL is %d units Long LOL",len);

    head = Delete_at_Beg(head);
    traversal(head);

    head = Delete_at_End(head);
    traversal(head);

    int pos = 3;
    head = Delete_at_Pos(head,pos);
    traversal(head);

}




