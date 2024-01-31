

#include <stdio.h>

#define MAX 5
int queue[MAX];
int front=-1,rear=-1;

void enqueue();
void dequeue();
void display();

int main(){
    int opt;

    while(1){
        printf(" press 1 for enqueue \n press 2 for dequeue  \n Enter your choice: ");
        scanf("%d",&opt);

        switch(opt){

            case 1:
            enqueue();
            break;

            case 2:
            dequeue();
            break;

            // case '3':
            // exit(0);
            // break;

            default:
            printf("You entered a wong nummber");
            break;
        }

    }
    
    return 0;
}

void enqueue(){
    int num;
    if(rear == MAX-1){
        printf("Queue is Full");
    }
    // else if(front == -1 && rear == -1){
    //     printf("Enter value: ");
    //     scanf("%d",&num);
    //     front = rear = 0;
    //     queue[rear]=num;   
    //     display();    
    
    // }
    else{
        if(front == -1){
            front = 0;
        }
        printf("Enter value: ");
        scanf("%d,",&num);
        rear++;
        queue[rear]=num;   

        display();    
    }

}

void dequeue(){
    if(rear == front == -1 || rear == front){
        printf(" queue is empty \n");
    }
    else{
        front++;
        printf("Element Deleted \n");
        display();    
    }

}

void display(){
    int i;
    if(rear == -1){
        printf("Queue is empty \n");
    }
    else{
        printf("Elements in the queue are: ");

        for(i=front ; i<= rear ; i++){
            printf("%d ,",queue[i]);
        }
        printf("\n ");

    }
    
}






