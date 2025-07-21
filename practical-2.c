#include <stdio.h>


int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        
        if (arr[mid] == target)
            return mid;

        
        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);

        
        return binarySearch(arr, mid + 1, right, target);
    }

   
    return -1;
}

int main() {
    int n, i, target;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements in sorted order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found in the array\n", target);

    return 0;
}
