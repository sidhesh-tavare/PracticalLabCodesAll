#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct Node** head, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    if (*head == NULL || (*head)->priority < priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL && temp->next->priority >= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("%d (priority %d) enqueued.\n", data, priority);
}

int dequeue(struct Node** head) {
    if (*head == NULL) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    struct Node* temp = *head;
    int value = temp->data;
    *head = (*head)->next;
    free(temp);
    return value;
}

void displayQueue(struct Node* head) {
    if (head == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("Priority Queue: ");
    while (temp != NULL) {
        printf("%d(priority %d) -> ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* pq = NULL;

    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 5);
    enqueue(&pq, 15, 3);
    enqueue(&pq, 30, 1);

    printf("\nPriority Queue after enqueue operations:\n");
    displayQueue(pq);

    printf("\nDequeued element: %d\n", dequeue(&pq));
    printf("Dequeued element: %d\n", dequeue(&pq));

    printf("\nPriority Queue after dequeue operations:\n");
    displayQueue(pq);

    return 0;
}
