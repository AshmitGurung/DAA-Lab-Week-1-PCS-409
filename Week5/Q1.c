#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void findMaxOccurrence(char arr[], int n)
    {
        int count[26] = {0};

    
         for (int i = 0; i < n; i++) {
            if (arr[i] >= 'a' && arr[i] <= 'z')
                count[arr[i] - 'a']++;
    }

    int maxOccurrence = 0;
    char maxChar = '\0';

    
    for (int i = 0; i < 26; i++) {
        if (count[i] > maxOccurrence) {
            maxOccurrence = count[i];
            maxChar = 'a' + i;
        }
    }

    if (maxOccurrence > 1)
        printf("%c - %d\n", maxChar, maxOccurrence);
    else
        printf("No Duplicates Present\n");
}

int main() {
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int n;
        printf("Enter the size of array: ");
        scanf("%d", &n);

        char arr[MAX_SIZE];
        printf("Enter the elements of the array: ");
        scanf("%s", arr);

        findMaxOccurrence(arr, n);
    }

    return 0;
}
