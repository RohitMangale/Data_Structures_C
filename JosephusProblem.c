#include <stdio.h>

// Function to simulate the Josephus problem using recursion and array-based queue
int josephus(int n, int k, int queue[], int front, int rear) {
    // Base case: If only one person is left, return their position
    if (n == 1)
        return queue[front];

    // Find the next person to be eliminated (k-1 steps in the circular queue)
    int steps = (k - 1) % n;

    // Eliminate the selected person by shifting the queue elements
    front = (front + steps) % n;

    // Move the eliminated person to the end of the queue
    rear = (rear + 1) % n;
    queue[rear] = queue[front];

    // Eliminate the person at the front of the queue
    front = (front + 1) % n;

    // Recursive call for the reduced problem
    return josephus(n - 1, k, queue, front, rear);
}

int main() {
    // Number of people
    int n = 5;

    // Elimination step
    int k = 0;

    // Array-based queue to represent the circle of people
    int queue[n];

    // Initialize the queue with person numbers
    for (int i = 0; i < n; i++) {
        queue[i] = i + 1;
    }

    // Call the recursive function to find the last remaining person
    int lastPerson = josephus(n, k, queue, 0, n - 1);

    // Output the result
    printf("The position of the last remaining person is: %d\n", lastPerson);

    return 0;
}
