#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

typedef struct {
    int front, rear, size;
    int array[MAX];
} CircularQueue;

void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(CircularQueue *q) {
    return (q->size == 0);
}

int isFull(CircularQueue *q) {
    return (q->size == MAX);
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->array[q->rear] = value;
    q->size++;
    printf("%d enqueued\n", value);
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->array[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    if (q->size == 0) {
        q->front = q->rear = -1;  // Reset queue when empty
    }
    printf("%d dequeued\n", value);
    return value;
}

void printQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    do {
        printf("%d ", q->array[i]);
        i = (i + 1) % MAX;
    } while (i != (q->rear + 1) % MAX);
    printf("\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);
    int choice, value;

    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue:(Rehbar khan[231P021]) ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                printQueue(&q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
