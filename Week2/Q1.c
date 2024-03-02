#include <stdio.h>


int binarySearch(int arr[], int n, int key) {
    int count = 0;
    int low = 0, high = n - 1;
    
   
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        
        if (arr[mid] == key) {
            count++;
            
            
            int left = mid - 1;
            while (left >= 0 && arr[left] == key) {
                count++;
                left--;
            }
            
            int right = mid + 1;
            while (right < n && arr[right] == key) {
                count++;
                right++;
            }
            
            return count;
        }
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    return 0; 

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
        
        int copies = binarySearch(arr, n, key);
        
        if (copies > 0)
            printf("%d %d\n", key, copies);
        else
            printf("Key not present\n");
    }
    
    return 0;
}
