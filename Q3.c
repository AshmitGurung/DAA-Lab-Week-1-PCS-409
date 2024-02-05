#include <stdio.h>

void Jump_search(int arr[], int n, int key) {
    int comparison = 0, flag = 0;
    
    if (arr[0] == key) {
        comparison = 1;
        printf("Present %d\n", comparison);
        return;
    }
    
    int range = 1;
    
    while (range < n && arr[range] <= key) {
        comparison++;
        range *= 2;
    }
    
    int l = range / 2, h = (range < n - 1) ? range : n - 1, mid;
    
    while (h >= l) {
        comparison++;
        mid = (h + l) / 2;
        
        if (arr[mid] == key) {
            flag = 1;
            break;
        } else if (arr[mid] > key) {
            h = mid - 1;
        } else if (arr[mid] < key) {
            l = mid + 1;
        }
    }
    
    if (flag)
        printf("Present %d\n", comparison);
    else
        printf("Not Present %d\n", comparison);
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[n];
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        int key;
        scanf("%d", &key);
        
        Jump_search(arr, n, key);
    }
    
    return 0;
}
