

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int height;
    struct node *left, *right;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int getbalance(struct node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

struct node *create(int root)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = root;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

struct node *preOrder(struct node *groot)
{
    if (groot != NULL)
    {
        printf("%d \t", groot->data);
        preOrder(groot->left);
        preOrder(groot->right);
    }
}

void *bl(struct node *groot)
{
    if (groot != NULL)
    {
        printf("%d, %d \t", groot->data, getbalance(groot));
        bl(groot->left);
        bl(groot->right);
    }
}

struct node *rightRotate(struct node *node)
{
    printf("\nPerformed right rotate \n");
    struct node *temp = node->left;
    struct node *temp2 = temp->right;

    temp->right = node;
    node->left = temp2;

    node->height = max(height(node->left), height(node->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;

    return temp;
}

struct node *leftRotate(struct node *node)
{

    printf("\nPerformed left rotate \n");

    struct node *temp = node->right;
    struct node *temp2 = temp->left;

    temp->left = node;
    node->right = temp2;

    node->height = max(height(node->left), height(node->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;

    return temp;
}

struct node *insert(struct node *node, int val)
{
    if (node == NULL)
    {
        return create(val);
    }
    if (val < node->data)
    {
        node->left = insert(node->left, val);
    }
    else if (val > node->data)
    {
        node->right = insert(node->right, val);
    }
    else
    {
        printf("Duplicate \n");
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getbalance(node);
    

    if (balance > 1 && val < node->left->data)
    {
        printf("Balance Factor: ");
        bl(node);
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && val > node->right->data)
    {
        printf("Balance Factor: ");
        bl(node);        
        return leftRotate(node);
    }

    // left right Case
    if (balance > 1 && val > node->left->data)
    {
        printf("Balance Factor: ");
        bl(node);

        node->left = leftRotate(node->left);
        printf("Balance Factor: ");
        bl(node);
        return rightRotate(node);
    }

    // Right left Case
    if (balance < -1 && val < node->right->data)
    {
        
        printf("Balance Factor: ");
        bl(node);

        node->right = rightRotate(node->right);
        printf("Balance Factor: ");
        bl(node);
        return leftRotate(node);
    }

    return node;
}

int main()
{
    struct node *root = NULL;
    int val;
    int opt = 1;

    while (opt)
    {
        printf("Enter Value : ");
        scanf("%d", &val);
        root = insert(root, val);

        printf("Balance Factor: ");
        bl(root);
        printf("\nPreorder : ");
        preOrder(root);

        printf("\n\nDo you want to continue (0,1): ");
        scanf("%d", &opt);
    }
    printf("\nPreorder : ");
    preOrder(root);
    printf(" \n");

    return 0;
}
