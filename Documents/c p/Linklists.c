#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void deleteStart(struct Node **head) {
    if (*head == NULL) {
        printf("Linked List Empty, nothing to delete\n");
        return;
    }

    struct Node *temp = *head;
    if (temp->next == *head) {
        *head = NULL;
    } else {
        struct Node *prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        prev->next = temp->next;
        *head = temp->next;
    }

    printf("%d deleted\n", temp->data);
    free(temp);
}

void insertStart(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }

    printf("%d inserted by Rehbar khan[231P021]\n", newNode->data);
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    printf("Linked List: ");
    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int n, m, value;

    printf("Enter the number of nodes to be inserted: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the value to be inserted: ");
        scanf("%d", &value);
        insertStart(&head, value);
    }

    printf("Enter the number of nodes to be deleted: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        deleteStart(&head);
    }

    display(head);
    return 0;
}
