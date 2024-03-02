#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return ((int)a - (int)b);
}

char* checkDuplicates(int arr[], int n) {
    // Sort the array
    qsort(arr, n, sizeof(int), compare);
    
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            return "YES";
        }
    }
    
    return "NO";
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
        
        printf("%s\n", checkDuplicates(arr, n));
    }
    
    return 0;
}
