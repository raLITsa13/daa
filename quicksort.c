#include<stdio.h>

void swap(double* a, double* b) {
    double t = *a;
    *a = *b;
    *b = t;
}

int partition(double arr[], int low, int high) {
    double pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(double arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    int size;
    fscanf(file, "%d", &size);

    double arr[size];
    for (int i = 0; i < size; i++) {
        fscanf(file, "%lf", &arr[i]);
    }

    fclose(file);

    quickSort(arr, 0, size - 1);

    FILE* outFile = fopen("output.txt", "w");
    for (int i = 0; i < size; i++) {
        fprintf(outFile, "%.2lf ", arr[i]);
    }
    fclose(outFile);

    return 0;
}
