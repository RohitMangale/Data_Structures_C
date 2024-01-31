
#include <stdio.h>
#include <stdlib.h>

#define N 5
int front = -1;
int rear = -1;
int arr[N];

void print()
{
    if (rear == -1)
    {
        printf("Underflow\n");
    }
    int i = front;
    printf("Queue: ");
    while (i != rear)
    {
        printf(" %d ", arr[i]);
        i = (i + 1) % N;
    }
    printf(" %d ", arr[i]);
    printf("\n");
}

void enqueue()
{
    if (((rear + 1) % N) == front)
    {
        printf("\nOverflow");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        printf("\nEnter element: ");
        scanf("%d", &arr[rear]);
    }
    else
    {
        rear = (rear + 1) % N;
        printf("\nEnter element: ");
        scanf("%d", &arr[rear]);
    }
    print();
}


void dequeue()
{
    if (rear == -1)
    {
        printf("Underflow\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % N;
        print();
    }
}

int main()
{

    int opt = 1;

    while (opt)
    {
        printf("\nPress 1-enqueue ,2-dequeue,3-exit ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;
        case 3:
            return 0;
            break;

        default:
            printf("\nYou entered wrong number");
            break;
        }
    }

    return 0;
}
