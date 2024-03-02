#include <stdio.h>
#include <stdlib.h>

int merge(int arr[], int left, int mid, int right) {
    int comparisons = 0;
    int inversions = 0;
    
    int left_size = mid - left + 1;
    int right_size = right - mid;
    
    int* left_array = (int*)malloc(left_size * sizeof(int));
    int* right_array = (int*)malloc(right_size * sizeof(int));
    
    for (int i = 0; i < left_size; i++)
        left_array[i] = arr[left + i];
    for (int j = 0; j < right_size; j++)
        right_array[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < left_size && j < right_size) {
        if (left_array[i] <= right_array[j]) {
            arr[k] = left_array[i];
            i++;
        } else {
            arr[k] = right_array[j];
            j++;
            inversions += mid - left + 1 - i;
        }
        k++;
        comparisons++;
    }
    
    while (i < left_size) {
        arr[k] = left_array[i];
        i++;
        k++;
    }
    
    while (j < right_size) {
        arr[k] = right_array[j];
        j++;
        k++;
    }
    
    free(left_array);
    free(right_array);
    
    return comparisons;
}

int merge_sort(int arr[], int left, int right) {
    int comparisons = 0;
    
    if (left < right) {
        int mid = left + (right - left) / 2;
        comparisons += merge_sort(arr, left, mid);
        comparisons += merge_sort(arr, mid + 1, right);
        comparisons += merge(arr, left, mid, right);
    }
    
    return comparisons;
}

void sort_and_count(int arr[], int n) {
    int comparisons = merge_sort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Comparisons = %d\n", comparisons);
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
        
        sort_and_count(arr, n);
    }
    
    return 0;
}
