#include <stdio.h>



int findElement(int arr[], int n) {

    int key;

    scanf("%d", &key);



    for (int i = 0; i < n; i++) {

        if (arr[i] == key) {

            return i + 1;

        }

    }



    return -1;

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



        int res = findElement(arr, n);



        if (res != -1) {

            printf("Present %d\n", res);

        } else {

            printf("Not Present\n");

        }

    }



    return 0;

}
