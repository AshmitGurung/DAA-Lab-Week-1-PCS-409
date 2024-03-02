#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

int quickSelect(int arr[], int low, int high, int K) {
    if (K > 0 && K <= high - low + 1) {
        int pi = partition(arr, low, high);

        if (pi - low == K - 1)
            return arr[pi];
        if (pi - low > K - 1)
            return quickSelect(arr, low, pi - 1, K);
        return quickSelect(arr, pi + 1, high, K - pi + low - 1);
    }
    return -1; 
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

        int K;
        printf("Enter the value of K: ");
        scanf("%d", &K);

        int KthSmallest = quickSelect(arr, 0, n - 1, K);

        if (KthSmallest != -1)
            printf("Kth smallest element is: %d\n", KthSmallest);
        else
            printf("Not present\n");
    }

    return 0;
}
