#include <stdio.h>

void insertionSort(int arr[], int n, int *comparisons, int *shifts) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        
        (*shifts)++;
        
    
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            
            (*shifts)++;
            
            (*comparisons)++;
        }
        
        arr[j + 1] = key;
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
        int shifts = 0;
        
        insertionSort(arr, n, &comparisons, &shifts);
        
        printf("Sorted array: ");
        printArray(arr, n);
        printf("Total number of comparisons: %d\n", comparisons);
        printf("Total number of shifts: %d\n", shifts);
    }
    
    return 0;
}
