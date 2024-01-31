#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <limits.h>

# define MAX 20
char str[MAX],stack[MAX];
int top=-1;

struct node
{
    char data;
    struct node *left;
    struct node *right;
};


void push(char c)
{
   stack[++top]=c;
}
char pop()
{
   return stack[top--];
}
char pre_post()
{
   int n,i,j=0; char c[20];
   char a,b,op;
   printf("Enter the prefix expression\n");
   scanf("%s",&str);
   n=strlen(str);
   for(i=0;i<MAX;i++)
   stack[i]='\0';
//    printf("Postfix expression is:\t");
   for(i=0;i<n;i++)
   {
      if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
      {
         push(str[i]);
      }
      else
      { c[j++]=str[i];
        while((top!=-1)&&(stack[top]=='@'))
        {
            a=pop(); c[j++]=pop();
        }
        push('@');
      }
   }
   c[j]='\0';
//    printf("%s",c);
    return c;
}

struct node *create(char data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->right = newnode->left = NULL;
    return newnode;
}


struct node *tree()
{
    struct node *stack1[100];
    int top = -1;

    char exp[] = pre_post();


    for(int i = 0 ; i != '\0' ; i++ )
    {
        char ch = exp[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') )
        {
            struct node *newnode = create(ch);
            stack[++top] = newnode;
            printf("Pushed in stack:%c \n",newnode->data);
        }
        else
        {
            struct node *newnode = create(ch);
            printf("read: %c \n",newnode->data);

            newnode->left = stack1[top--];
            printf("Pop from stack: %c \n",newnode->left->data);

            newnode->right = stack1[top--];
            printf("Pop from stack: %c \n",newnode->right->data);

            stack1[++top] = newnode;
            printf("Pushed in stack: %c \n",newnode->data);
        }

    }
    printf("\n");
    return stack1[top--];
}

struct node *io(struct node *groot)
{
    if (groot != NULL)
    {
        io(groot->left);
        printf("%c ", groot->data);
        io(groot->right);
    }
}

int main()
{

    struct node *root = tree();
    printf("Inorder: ");
    io(root);

    printf("\n");

    return 0;
}









