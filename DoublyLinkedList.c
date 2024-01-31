

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
}*head,*newnode,*tail;


void display();
void insert_beginning();
void insert_end();
void insert_position();
void insert_after_position();
void delete_beginning();
void delete_end();
void delete_position();

int count;

int main(){

    int num,opt;
    head=NULL;
    printf("Enter the Number of nodes: ");
    scanf("%d",&num);


    for(int i = 1; i<=num; i++){

        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data %d :",i);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;

        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }

    }

    display();
    printf("\n----------------------------------------------- \n");


    while(1){
        printf("\n press 1 to insert at beginning \t2-insert at end \t3-insert at position \t4-insert after position \t5-delete at beginning \t6-delete at end \t7-delete at position \t0-exit \n Enter your choice: ");
        scanf("%d",&opt);

        switch(opt){

            case 1:
            insert_beginning();
            break;

            case 2:
            insert_end();
            break;

            case 3:
            insert_position();
            break;

            case 4:
            insert_after_position();
            break;

            case 5:
            delete_beginning();
            break;

            case 6:
            delete_end();
            break;

            case 7:
            delete_position();
            break;

            case 0:
            exit(0);
            break;

            default:
            printf("You entered a wong nummber \n");
            break;
        }

    }



    return 0;
}


void insert_beginning(){
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;

    newnode->next=head;
    head=newnode;

    display();

}

void insert_end(){
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;

    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;

    display();

}

void insert_position(){
    struct node *temp;
    temp=head;
    int i=1,pos;

    
    printf("Enter the position: ");
    scanf("%d",&pos);

    if(pos>count || pos<=0){
        printf("Invalid Position");
        exit(0);
    }
    else if(pos==1){
        insert_beginning();
    }
    else{
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d",&newnode->data);

        while(i<pos-1){
            temp=temp->next;
            i++;
        }

        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->prev=newnode;
    }
    display();
}

void insert_after_position(){

    struct node *temp;
    temp=head;
    int i=1,pos;

    
    printf("Enter the position: ");
    scanf("%d",&pos);

    if(pos>count){
        printf("Invalid Position");
        printf("Invalid Position");
        printf("Invalid Position");
        printf("Invalid Position");
        exit(0);
    }
    else if(pos<=0){
        printf("Invalid Position");
        printf("Invalid Position");
        printf("Invalid Position");
        printf("Invalid Position");
        exit(0);
    }
    else{
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d",&newnode->data);

        while(i<pos){
            temp=temp->next;
            i++;
        }

        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->prev=newnode;

    }

    display();

}

void delete_beginning(){
    struct node *temp;
    temp=head;
    if(head==NULL){
        printf("List is empty\n");
        
    }
    else{
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    display();

}

void delete_end(){
    struct node *temp;
    temp=tail;
        if(tail==NULL){
        printf("List is empty\n");
        
    }
    else{
        tail->prev->next=NULL;
        tail=tail->prev;
        free(temp);
    }
    display();


}

void delete_position(){
    int pos,i=1;
    struct node *temp;


    printf("Enter position: ");
    scanf("%d",&pos);
    
    if(pos>count || pos<=0){
        printf("Invalid Position");
        exit(0);
    }
    else if(pos==1){
        delete_beginning();
    }
    else{
        temp=head;

        while(i<pos){
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        
    }
    display();

}


void display(){
    printf("Data in the list: ");
    struct node *temp;
    temp=head;
    count=0;
    if(head==NULL){
        printf("List is Empty");
        exit(0);
    }

    while(temp!=NULL){
        printf(" %d \t",temp->data);
        temp=temp->next;
        count++;
    }
}


