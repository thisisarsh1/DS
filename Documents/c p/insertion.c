#include <stdio.h>

void insertElement(int arr[], int *n, int position, int element) {
    for (int i = *n; i >= position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = element;
    (*n)++;
}

int main() {
    int arr[100], n, element, position;

    printf("Number of elements entered by Rehbar Khan [231P021]: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to insert the element: ");
    scanf("%d", &position);
    
    printf("Enter the element to insert: ");
    scanf("%d", &element);

    if (position > 0 && position <= n + 1) {
        insertElement(arr, &n, position, element);

        printf("Array after insertion:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Invalid position!\n");
    }

    return 0;
}