#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full.\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue *q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

void removeNegatives(Queue *q) {
    Queue tempQ;
    initQueue(&tempQ);

    while (!isEmpty(q)) {
        int value = dequeue(q);
        if (value >= 0) {
            enqueue(&tempQ, value);
        }
    }

    while (!isEmpty(&tempQ)) {
        enqueue(q, dequeue(&tempQ));
    }
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, -5);
    enqueue(&q, 20);
    enqueue(&q, -8);
    enqueue(&q, 15);

    printf("Original queue:\n");
    displayQueue(&q);

    removeNegatives(&q);

    printf("Queue after removing negatives:\n");
    displayQueue(&q);

    return 0;
}