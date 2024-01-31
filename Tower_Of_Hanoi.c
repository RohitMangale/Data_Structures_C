#include <stdio.h>

#define MAX_DISKS 10

int source[MAX_DISKS], auxiliary[MAX_DISKS], destination[MAX_DISKS];
int sourceTop = -1, auxiliaryTop = -1, destinationTop = -1;

void push(int stack[], int *top, int disk) {
    if (*top < MAX_DISKS - 1) {
        stack[++(*top)] = disk;
    } else {
        printf("Error: Stack overflow\n");
    }
}

int pop(int stack[], int *top) {
    if (*top >= 0) {
        return stack[(*top)--];
    } else {
        printf("Error: Stack underflow\n");
        return -1; // Error value
    }
}

void displayStack(int stack[], int top, const char *stackName) {
    printf("%s Stack: ", stackName);
    for (int i = 0; i <= top; ++i) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void moveDisk(int sourceStack[], int *sourceTop, int destinationStack[], int *destinationTop, const char *sourceName, const char *destinationName) {
    int disk = pop(sourceStack, sourceTop);
    if (disk != -1) {
        push(destinationStack, destinationTop, disk);
        printf("Move disk %d from %s to %s\n", disk, sourceName, destinationName);
    }
}

void hanoi(int n, int source[], int *sourceTop, int auxiliary[], int *auxiliaryTop, int destination[], int *destinationTop) {
    if (n > 0) {
        hanoi(n - 1, source, sourceTop, destination, destinationTop, auxiliary, auxiliaryTop);
        moveDisk(source, sourceTop, destination, destinationTop, "Source", "Destination");
        displayStack(source, *sourceTop, "Source");
        displayStack(auxiliary, *auxiliaryTop, "Auxiliary");
        displayStack(destination, *destinationTop, "Destination");
        hanoi(n - 1, auxiliary, auxiliaryTop, source, sourceTop, destination, destinationTop);
    }
}

int main() {
    int numDisks;

    printf("Enter the number of disks (max %d): ", MAX_DISKS);
    scanf("%d", &numDisks);

    if (numDisks > MAX_DISKS || numDisks <= 0) {
        printf("Invalid number of disks. Please enter a number between 1 and %d.\n", MAX_DISKS);
        return 1;
    }

    // Initialize source stack
    for (int i = numDisks; i > 0; --i) {
        push(source, &sourceTop, i);
    }

    displayStack(source, sourceTop, "Source");
    displayStack(auxiliary, auxiliaryTop, "Auxiliary");
    displayStack(destination, destinationTop, "Destination");

    hanoi(numDisks, source, &sourceTop, auxiliary, &auxiliaryTop, destination, &destinationTop);

    return 0;
}
