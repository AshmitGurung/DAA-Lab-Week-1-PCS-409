#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high, int *comparisons, int *swaps) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            (*swaps)++;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    (*swaps)++;
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int *comparisons, int *swaps) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, swaps);
        quickSort(arr, low, pi - 1, comparisons, swaps);
        quickSort(arr, pi + 1, high, comparisons, swaps);
    }
}

void sort_and_count(int arr[], int n) {
    int comparisons = 0;
    int swaps = 0;

    quickSort(arr, 0, n - 1, &comparisons, &swaps);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Comparisons = %d\n", comparisons);
    printf("Swaps = %d\n", swaps);
}

int main() {
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int n;
        printf("Enter the size of array: ");
        scanf("%d", &n);

        int arr[n];
        printf("Enter the elements of the array: ");
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        int comparisons = 0;
        int swaps = 0;

      
        srand(time(NULL));
        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        sort_and_count(arr, n);
    }

    return 0;
}

