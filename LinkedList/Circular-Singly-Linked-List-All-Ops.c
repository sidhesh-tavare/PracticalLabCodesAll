#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newnode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = temp;  // Points to itself in circular list
    return temp;
}

void traversal(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d > ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

bool searchLL(struct Node* head, int target) {
    if (head == NULL) {
        return false;
    }

    struct Node* current = head;
    do {
        if (current->data == target) {
            return true;
        }
        current = current->next;
    } while (current != head);
    return false;
}

int findlengthofLL(struct Node* head) {
    if (head == NULL) return 0;
    
    int length = 1;
    struct Node* current = head;
    while (current->next != head) {
        length++;
        current = current->next;
    }
    return length;
}

struct Node* InsertBeg(struct Node* head, int val) {
    struct Node* new_node = newnode(val);
    if (head == NULL) {
        return new_node;
    }
    
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
    return new_node;
}

struct Node* InsertEnd(struct Node* head, int val) {
    struct Node* new_node = newnode(val);
    if (head == NULL) {
        return new_node;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
    return head;
}

struct Node* InsertatPos(struct Node* head, int val, int pos) {
    if (pos < 1) {
        printf("Invalid Position\n");
        return head;
    }

    struct Node* new_node = newnode(val);
    if (pos == 1) {
        return InsertBeg(head, val);
    }

    struct Node* temp = head;
    int count = 1;
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (temp->next == head && count < pos - 1) {
        printf("Invalid Position\n");
        return head;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

struct Node* Delete_at_Beg(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == head) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    struct Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    head = head->next;
    tail->next = head;
    free(temp);
    return head;
}

struct Node* Delete_at_End(struct Node* head) {
    if (head == NULL) {
        printf("empty List\n");
        return NULL;
    }

    if (head->next == head) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = head;
    return head;
}

struct Node* Delete_at_Pos(struct Node* head, int pos) {
    if (head == NULL || pos < 1) {
        return head;
    }

    if (pos == 1) {
        return Delete_at_Beg(head);
    }

    struct Node* temp = head;
    int count = 1;
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (temp->next == head || count < pos - 1) {
        printf("Invalid Position\n");
        return head;
    }

    struct Node* node_to_delete = temp->next;
    temp->next = temp->next->next;
    free(node_to_delete);
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
