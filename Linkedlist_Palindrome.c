

#include <stdio.h>
#include <stdlib.h>

int num = 0;

struct node
{
    int data;
    struct node *next;
} *head = NULL, *temp,*extra,*prev,*tail;

void print()
{
    temp = head;
    printf("\nList: ");

    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        if (temp->next != NULL)
        {
            printf(" --> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int palindrome()
{
    if(num == 1){
        printf("\nOnly 1 node");
        return 1;
    }
    int stop = num / 2;
    printf("\nStop = %d",stop);
    temp = head;

    for (int i = 0; i < stop; i++)
    {
        temp = temp->next;
    }

    if (num % 2 == 1)
    {
        tail  = temp;
        prev = tail;
        while(temp != NULL){
            extra = temp->next;
            temp->next = prev;
            prev = temp;
            temp = extra;
        }
        tail->next = NULL;
        extra = prev;
        temp = head;
        while(extra != temp){
            if(temp->data != extra->data){
                return 0;
            }
            temp = temp->next;
            extra = extra->next;
        }        
        return 1;
    }
    else{
        tail = temp;
        temp = temp->next ;
        prev = temp;
        prev->next = NULL;
        tail->next = NULL;
        temp = temp->next ;
        while(temp != NULL){
            extra = temp->next;
            temp->next = prev;
            prev = temp;
            temp = extra;
        }
        extra = prev;
        temp = head;
        while(temp != NULL){
            if(temp->data != extra->data){
                return 0;
            }
            temp = temp->next;
            extra = extra->next;
        }        
        return 1;

    }



    return 1;
}

int main()
{

    printf("Enter the number of node: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Element %d : ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
    }

    print();

    if(palindrome() == 0 ){
        printf("\nNot Palindrome");
    }
    else{
        printf("\nPalindrome");
    }

    return 0;
}
