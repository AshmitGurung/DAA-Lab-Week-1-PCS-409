#include <stdio.h>

void findIndices(int arr[], int n) {
    int found = 0;
    
    for (int k = n - 1; k >= 0; k--) {
        int i = 0, j = k - 1; 
        
        while (i < j) {
            if (arr[i] + arr[j] == arr[k]) {
                found = 1;
                printf("%d %d %d\n", i+1, j+1, k+1); 
                break;
            } else if (arr[i] + arr[j] < arr[k]) {
                i++; 
            } else {
                j--; 
            }
        }
        
        if (found)
            break; 
    }
    
    if (!found)
        printf("No such triplet exists\n"); 
}

int main() {
    int T;
    scanf("%d", &T); 
    
    while (T--) {
        int n;
        scanf("%d", &n); 
        int arr[n];
        
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        
        findIndices(arr, n);
    }
    
    return 0;
}
