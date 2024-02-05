#include <stdio.h>

int binary_search(int arr[], int low, int high, int key, int *comparisons) {
    while (low <= high) {
        (*comparisons)++;
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return 1;  
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return 0; 
}

int main() {
    int size, key;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the sorted array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int comparisons = 0;

    int result = binary_search(arr, 0, size - 1, key, &comparisons);

    if (result) {
        printf("%d is present in the array.\n", key);
    } else {
        printf("%d is not present in the array.\n", key);
    }

    printf("Total comparisons: %d\n", comparisons);

    return 0;
}
