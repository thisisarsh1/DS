#include <stdio.h>
void deleteElement(int arr[], int *n, int position) {
    if (position >= *n + 1 || position < 1) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = position - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;
}

int main() {
    int arr[100], n, position;

    printf("ELEMENTS ENTERED BY Rehbar khan [231P021]: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to delete the element: ");
    scanf("%d", &position);

    if (position >= 1 && position <= n) {
        deleteElement(arr, &n, position);

        printf("Array after deletion:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Invalid position!\n");
    }

    return 0; 
}