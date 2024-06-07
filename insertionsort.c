#include <stdio.h>

// Function to perform insertion sort
void insertionSort(float arr[], int n) {
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print an array
void printArray(float arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    insertionSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
