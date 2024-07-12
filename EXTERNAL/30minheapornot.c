#include <stdio.h>

int isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (arr[i] > arr[2 * i + 1] || (2 * i + 2 < n && arr[i] > arr[2 * i + 2]))
            return 0;
    }
    return 1;
}

int main() {
    int arr[] = {10, 20, 15, 30, 40, 35, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (isMinHeap(arr, n))
        printf("The given array represents a min heap\n");
    else
        printf("The given array does not represent a min heap\n");
    return 0;
}