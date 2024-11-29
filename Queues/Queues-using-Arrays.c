#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#define SIZE 10

struct Queue{
    int items[SIZE];
    int front;
    int rear;
};

void initQ(struct Queue* q){
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q){
    return (q->front==-1);
}

int isFull(struct Queue* q){
    return(q->rear == SIZE-1);
}

void enqueue(struct Queue* q,int val){
    if(isFull(q)){
        printf("Full");
        return;
    }
    if(isEmpty(q)) q->front=0;
    q->rear++;
    q->items[q->rear]= val;
    printf("Inserted %d\n",val);
}

int deque(struct Queue* q){
    if(q->front == -1){
        printf("Empty List");
        return 0000;
    }
    printf("Dequeue Operation\n");
    int value = q->items[q->front];
    q->front++;
    return value;
}


int display(struct Queue* q){
    if(isEmpty(q)){
        printf("Empty\n");
        return 0000;
    }
    printf("Queue Elements : \n");
    for(int i = q->front ; i<= q->rear ;i++){
        printf("%d ",q->items[i]);
    }
    printf("\n");
}


int main(){
    struct Queue q;
    initQ(&q);

    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    enqueue(&q,5);
    display(&q);

    deque(&q);
    display(&q);
 
}