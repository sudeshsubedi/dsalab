#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int p, int r) {
    int x = arr[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (arr[j] < x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

void quicksort(int arr[], int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    quicksort(arr, 0, n - 1);

    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}