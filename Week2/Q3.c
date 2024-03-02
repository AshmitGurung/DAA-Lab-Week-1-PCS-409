#include <stdio.h>


int countPairsWithDifference(int arr[], int n, int key) {
    int count = 0;
    
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            
            if (arr[i] - arr[j] == key || arr[j] - arr[i] == key)
                count++;
        }
    }
    
    return count;
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
        
        int key;
        scanf("%d", &key); 
        
        int pairsCount = countPairsWithDifference(arr, n, key);
        
        printf("%d\n", pairsCount);
    }
    
    return 0;
}
