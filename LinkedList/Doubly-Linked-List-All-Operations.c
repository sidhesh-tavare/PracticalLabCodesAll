#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* newnode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void traversal(struct Node* head) {
    struct Node* current = head;
    printf("\n");
    while (current != NULL) {
        printf("%d > ", current->data);
        current = current->next;
    }
    printf("\n");
}

bool searchLL(struct Node* head, int target) {
    while (head != NULL) {
        if (head->data == target) return true;
        head = head->next;
    }
    return false;
}

int findlengthofLL(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

struct Node* InsertBeg(struct Node* head, int val) {
    struct Node* new_node = newnode(val);
    if (head != NULL) {
        head->prev = new_node;
    }
    new_node->next = head;
    head = new_node;
    return head;
}

struct Node* InsertEnd(struct Node* head, int val) {
    struct Node* new_node = newnode(val);
    if (head == NULL) {
        return new_node;
    }
    struct Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
    new_node->prev = curr;
    return head;
}

struct Node* Delete_at_Beg(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

struct Node* Delete_at_End(struct Node* head) {
    if (head == NULL) {
        printf("empty List\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    return head;
}

struct Node* InsertatPos(struct Node* head, int val, int pos) {
    if (pos < 1) {
        printf("Invalid Position\n");
        return head;
    }

    if (pos == 1) {
        return InsertBeg(head, val);
    }

    struct Node* new_node = newnode(val);
    struct Node* curr = head;
    for (int i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Position out of bounds\n");
        free(new_node);
        return head;
    }

    new_node->next = curr->next;
    new_node->prev = curr;

    if (curr->next != NULL) {
        curr->next->prev = new_node;
    }
    curr->next = new_node;

    return head;
}

struct Node* Delete_at_Pos(struct Node* head, int pos) {
    if (head == NULL || pos < 1) {
        printf("Invalid position\n");
        return head;
    }

    if (pos == 1) {
        return Delete_at_Beg(head);
    }

    struct Node* curr = head;
    for (int i = 1; i < pos && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Position out of bounds\n");
        return head;
    }

    if (curr->prev != NULL) {
        curr->prev->next = curr->next;
    }
    if (curr->next != NULL) {
        curr->next->prev = curr->prev;
    }
    free(curr);

    return head;
}

int main() {
    struct Node* head = NULL;

    head = InsertBeg(head, 10);
    head = InsertBeg(head, 20);
    head = InsertBeg(head, 30);

    printf("After Inserting at beg we get : \n");
    traversal(head);

    head = InsertEnd(head, 40);
    head = InsertEnd(head, 50);

    printf("Inserting at end LL = ");
    traversal(head);

    head = InsertatPos(head, 25, 2);
    printf("Inserting 25 at position 2: ");
    traversal(head);

    int target = 40;
    if (searchLL(head, target)) printf("Found in LL\n");
    else printf("Not Found Bhratashree!\n");

    target = 100;
    if (searchLL(head, target)) printf("Found in LL\n");
    else printf("Not Found Bhratashree!\n");

    int len = findlengthofLL(head);
    printf("Your LL is %d units Long LOL\n", len);

    head = Delete_at_Beg(head);
    printf("After deleting the first node: \n");
    traversal(head);

    head = Delete_at_End(head);
    printf("After deleting the last node: \n");
    traversal(head);

    head = Delete_at_Pos(head, 3);
    printf("After deleting node at position 3: \n");
    traversal(head);

    return 0;
}
