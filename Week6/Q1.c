#include <stdio.h>

int main() 
{
    int n, m, i, j;
    printf("Enter the size of first array: ");
    scanf("%d", &n);
    int arr1[n];
    printf("Enter elements of first array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr1[i]);
    
    printf("Enter the size of second array: ");
    scanf("%d", &m);
    int arr2[m];
    printf("Enter elements of second array: ");
    for (j = 0; j < m; j++)
        scanf("%d", &arr2[j]);
    
    i = 0;
    j = 0;
    while (i < n && j < m) 
    {
        if (arr1[i] == arr2[j]) 
        {
            printf("%d ", arr1[i++]);
        } else if (arr1[i] < arr2[j])
        {
            i++;
        } else 
        {
            j++;
        }
    }
    return 0;
}
