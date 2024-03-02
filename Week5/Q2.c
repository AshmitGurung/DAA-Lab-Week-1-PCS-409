#include <stdio.h>
#include <stdlib.h>

void findElementsWithSum(int arr[], int n, int key) {
    
    qsort(arr, n, sizeof(int), compar);

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == key) {
            printf("%d %d\n", arr[left], arr[right]);
            return;
        } else if (sum < key) {
            left++;
        } else {
            right--;
        }
    }

    printf("No Such Elements Exist\n");
}

int compar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
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

        int key;
        printf("Enter the key: ");
        scanf("%d", &key);

        findElementsWithSum(arr, n, key);
    }

    return 0;
}
