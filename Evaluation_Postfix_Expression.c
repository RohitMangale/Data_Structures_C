#include <stdio.h>
#include <stdlib.h>

#define N 100

int stack[N];
char post[N];
int top = -1;

int isop(char ch)
{
    return (ch == '*' || ch == '^' || ch == '/' || ch == '-' || ch == '+');
}


int operation(int ch1, int ch2, char op)
{
    switch (op)
    {
    case '+':
        return ch1 + ch2;

    case '-':
        return ch1 - ch2;

    case '*':
        return ch1 * ch2;

    case '/':
        if (ch2 != 0)
        {
            return ch1 / ch2;
        }
        else
        {
            printf("Error: Division by zero");
            exit(0);
        }

    case '^':
        return ch1 ^ ch2;

    default:
        return 0;
    }
}

void eval()
{
    for (int i = 0; post[i] != '\0'; i++)
    {
        char token = post[i];
        printf("\n Token : %c",token);

        if (token >= '1' && token <= '9')
        {
            stack[++top] = token - '0';
            printf("\npushing in stack : %d",stack[top]);
        }
        else if (isop(token))
        {
            int op2 = stack[top--];
            printf("\npopping from stack : %d",op2);

            int op1 = stack[top--];
            printf("\npopping from stack : %d",op1);

            printf("\nOperation on %d %c %d ",op1,token,op2);
            int result = operation(op1, op2, token);

            stack[++top] = result;
            printf("\npushing in stack : %d",stack[top]);

        }
    }
}

int main()
{

    printf("\nEnter Expression: ");
    scanf("%s", post);

    eval();
    
    printf("\n");
    printf("\nResult : %d", stack[top]);

    return 0;
}
