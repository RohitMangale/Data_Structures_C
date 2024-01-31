#include <stdio.h>

// Function to perform heapify operation on a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        // Swap the root with the largest element
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to perform heapsort
void heapsort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to extract the maximum element (delete the max element) from the heap
int extractMax(int arr[], int *n) {
    if (*n == 0)
        return -1; // Heap is empty

    // Store the max element and remove it from the heap
    int max = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;

    // Heapify the root
    heapify(arr, *n, 0);

    return max;
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    // Perform heapsort
    heapsort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    // Extract max element
    int max = extractMax(arr, &n);
    if (max != -1)
        printf("Max element extracted: %d\n", max);
    else
        printf("Heap is empty, cannot extract.\n");

    return 0;
}
