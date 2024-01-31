#include <stdio.h>
#include <string.h>
#define N 100

char stack[N];
char prefix[N];
char infix[N];

int top = -1;

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
        return 1;

    case '-':
        return 1;

    case '*':
        return 2;

    case '/':
        return 2;

    default:
        return 0;
    }
}

int ischaracter(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '1' && ch <= '9'));
}

int isoperand(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void reverse()
{
    int h = strlen(prefix) - 1;
    printf("\nh : %d", h);
    for (int i = 0; i <= h / 2; i++)
    {
        char temp = prefix[i];
        prefix[i] = prefix[h - i];
        prefix[h - i] = temp;
    }
}

void infixtoprefix()
{
    int i, j;
    for (i = 0, j = 0; infix[i] != '\0'; i++)
    {
        if (ischaracter(infix[i]))
        {
            prefix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                prefix[j++] = stack[top--];
            }
            if (top != -1)
            {
                top--;
            }
        }
        else if (isoperand(infix[i]))
        {
            if (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
            {
                prefix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }
    while (top != -1)
    {
        prefix[j++] = stack[top--];
    }
    prefix[j] = '\0';

    reverse();
}

int main()
{

    printf("\nEnter infix:");
    scanf("%s", infix);

    infixtoprefix();

    printf("\nPrefix expression: %s", prefix);
    return 0;
}
