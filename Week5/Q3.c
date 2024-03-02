#include <stdio.h>

void findCommonElements(int arr1[], int arr2[], int m, int n) {
    int i = 0, j = 0;

    printf("Common Elements: ");
    while (i < m && j < n) {
        if (arr1[i] == arr2[j]) {
            printf("%d ", arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
    printf("\n");
}

int main() {
    int m, n;
    printf("Enter the size of the first array: ");
    scanf("%d", &m);

    int arr1[m];
    printf("Enter the elements of the first array: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &arr1[i]);

    printf("Enter the size of the second array: ");
    scanf("%d", &n);

    int arr2[n];
    printf("Enter the elements of the second array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr2[i]);

    findCommonElements(arr1, arr2, m, n);

    return 0;
}
