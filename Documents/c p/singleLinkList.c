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
    *head = (*head)->next;
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
    newNode->next = *head;
    *head = newNode;
    printf("%d inserted\n", newNode->data);
}

void display(struct Node *head) {
    printf("Linked List: ");
    struct Node *node = head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int n, i, value;
    
    printf("Enter the number of nodes to be inserted: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Value inserted by Rehbar Khan[231P021]: ");
        scanf("%d", &value);
        insertStart(&head, value);
    }
    
    display(head);
    
    printf("Enter the number of nodes to be deleted: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        deleteStart(&head);
    }
    
    display(head);
    return 0;
}
