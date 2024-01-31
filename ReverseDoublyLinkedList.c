

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next,*prev;
}*head=NULL, *temp,*extra,*tail;

int count=0;

void display(){   
    printf("\nList is : ");
    if(head==NULL){
        printf("\nDisplay: List is empty\n");
    }
    else{
        temp=head;
        while(temp!= NULL){
            printf("%d  \t",temp->data);
            temp=temp->next;
        }
    }
}


void reversal(){
    temp=head;
    while(temp!=NULL){

    extra= temp->next;
    temp->next =temp->prev;
    temp->prev=extra;
    temp=extra;
    }
    printf("\nAfter Reversal: ");

    temp = tail;
    tail = head;
    head = temp;

    display();
    printf("\nHead: %d \t Tail: %d \n",head->data,tail->data);
}

int main()
{
    int num;

    printf("Enter the number of nodes: ");
    scanf("%d",&num);
    if(num == 0){
        printf("Number of nodes cannot be zero");
        return 0;
    }

    for(int i = 1; i<=num ; i++ ){

        struct node *newnode =  (struct node *)malloc(sizeof(struct node));        
        printf("Enter value %d :",i);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;

        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next = newnode;
            newnode->prev = tail;
            tail=newnode;
        }

    }

    printf("\nBefore Reversal: ");
    display();
    printf("\nHead: %d \t Tail: %d \n",head->data,tail->data);

    reversal();

    


    return 0;
}













