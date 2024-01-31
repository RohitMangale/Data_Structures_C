#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right, *left;
};

struct node *rootnode(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int val)
{
    if (root == NULL)
    {
        return rootnode(val);
    }
    else if (val == root->data)
    {
        printf("\nDuplicate");
    }
    else if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    return root;
}

void in(struct node *root)
{
    if (root != NULL)
    {
        in(root->left);
        printf(" %d ", root->data);
        in(root->right);
    }
}

void pre(struct node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
        pre(root->left);
        pre(root->right);
    }
}

void post(struct node *root)
{
    if (root != NULL)
    {
        post(root->left);
        post(root->right);
        printf(" %d ", root->data);
    }
}

int main()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    int val, opt = 1;

    printf("Enter value: ");
    scanf("%d", &val);
    root = rootnode(val);

    while (opt)
    {
        printf("Enter value: ");
        scanf("%d", &val);
        insert(root, val);

        printf("Do you want to continue(0,1):");
        scanf("%d", &opt);
    }

    printf("\nInOrder: ");
    in(root);

    printf("\nPreOrder: ");
    pre(root);

    printf("\nPostOrder: ");
    post(root);

    return 0;
}