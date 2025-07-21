#include <stdio.h>

void printArray(int arr[], int start, int end, const char *label) {
    printf("%s", label);
    for (int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printPass(int arr[], int start, int end) {
    printf("Pass: ");
    for (int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1, temp;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // swap arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    printPass(arr, low, high);

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n, i;
    printf("Number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printArray(arr, 0, n - 1, "Original array: ");
    quickSort(arr, 0, n - 1);
    printArray(arr, 0, n - 1, "Sorted array: ");
    return 0;
}
