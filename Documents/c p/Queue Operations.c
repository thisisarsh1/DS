#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int front, rear, size;
    int array[MAX];
} LinearQueue;

void initQueue(LinearQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(LinearQueue *q) {
    return (q->size == 0);
}

int isFull(LinearQueue *q) {
    return (q->size == MAX);
}

void enqueue(LinearQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = value;
    q->size++;
}

int dequeue(LinearQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->array[q->front];
    q->front++;
    q->size--;
    return value;
}
int front(LinearQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->array[q->front];
}

void printQueue(LinearQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}

int main() {
    LinearQueue q;
    initQueue(&q);
    int choice, value;
    do {
        printf("\nQueue Operations Menu (Generated By Rehbar khan [231P0216]):\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Check if Queue is Empty\n");
        printf("5. Check if Queue is Full\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (isFull(&q)) {
                    printf("Queue is full!\n");
                } else {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(&q, value);
                }
                break;
            case 2:
                if (isEmpty(&q)) {
                    printf("Queue is empty!\n");
                } else {
                    printf("Dequeued: %d\n", dequeue(&q)); 
                }
                break;
            case 3:
                printQueue(&q);
                break;
            case 4:
                if (isEmpty(&q)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 5:
                if (isFull(&q)) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}
