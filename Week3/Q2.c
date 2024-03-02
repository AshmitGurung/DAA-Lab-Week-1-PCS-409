#include <stdio.h>

void selectionSort(int arr[], int n, int *comparisons, int *swaps) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
           
            (*comparisons)++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
      
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
        
        (*swaps)++;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int n;
        scanf("%d", &n);
        
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        int comparisons = 0;
        int swaps = 0;
        
        selectionSort(arr, n, &comparisons, &swaps);
        
        printf("Sorted array: ");
        printArray(arr, n);
        printf("Total number of comparisons: %d\n", comparisons);
        printf("Total number of swaps: %d\n", swaps);
    }
    
    return 0;
}
