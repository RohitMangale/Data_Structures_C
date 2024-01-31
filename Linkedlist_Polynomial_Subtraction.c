#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coe, expo;
    struct node *next;
};

void create(struct node **poly)
{

    int coe, expo, opt = 1;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    *poly = temp;

    while (opt)
    {

        printf("\nEnter Coefficient: ");
        scanf("%d", &coe);

        printf("Enter exponent: ");
        scanf("%d", &expo);

        temp->expo = expo;
        temp->coe = coe;
        temp->next = NULL;

        printf("\nDo you want to continue(0,1): ");
        scanf("%d", &opt);

        if (opt)
        {
            temp->next = (struct node *)malloc(sizeof(struct node));
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

void addition(struct node *first, struct node *second, struct node **result)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    *result = temp;
    while (first && second)
    {

        if (first->expo > second->expo)
        {
            temp->expo = first->expo;
            temp->coe = first->coe;
            first = first->next;
        }
        else if (first->expo < second->expo)
        {
            temp->expo = second->expo;
            temp->coe = second->coe;
            second = second->next;
        }
        else if (first->expo = second->expo)
        {
            temp->expo = first->expo;
            temp->coe = first->coe - second->coe;
            first = first->next;
            second = second->next;
        }

        if (first && second)
        {
            temp->next = (struct node *)malloc(sizeof(struct node));
            temp = temp->next;
            temp->next = NULL;
        }
    }
    while (first || second)
    {
        if (first)
        {
            temp->next = first;
            break;
        }
        else if (second)
        {
            temp->next = second;
            break;
        }
    }
}

void display(struct node *poly)
{
    while (poly != NULL)
    {
        printf(" %d,%d ", poly->coe, poly->expo);
        if (poly->next != NULL)
            printf("-->");

        poly = poly->next;
    }
    printf("\n");
}

int main()
{
    struct node *first = NULL;
    struct node *second = NULL;
    struct node *result = NULL;

    printf("\nFirst Polynomial: ");
    create(&first);

    printf("\nSecond Polynomial: ");
    create(&second);

    addition(first, second, &result);

    display(first);
    display(second);
    display(result);

    return 0;
}
