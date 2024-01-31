#include <stdio.h>

#define MAX_SIZE 100

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0; // For '(' and ')'
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    char stack[MAX_SIZE];
    int top = -1; // Initialize stack top

    int i, j;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        // If the character is an operand or '(' or ')'
        if ((infix[i] >= '0' && infix[i] <= '9') || (infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) 
        {
            postfix[j++] = infix[i];
        } 
        else if (infix[i] == '(') 
        {
            stack[++top] = infix[i];
        } 
        else if (infix[i] == ')') {
            // Pop and append operators from the stack until '(' is encountered
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top != -1) {
                // Pop '(' from the stack
                top--;
            }
        } 
        else if (isOperator(infix[i])) {
            // Pop and append operators from the stack while precedence is greater or equal
            while (top != -1 && getPrecedence(stack[top]) >= getPrecedence(infix[i])) {
                postfix[j++] = stack[top--];
            }
            // Push the current operator onto the stack
            stack[++top] = infix[i];
        }
    }

    // Pop any remaining operators from the stack and append to the postfix expression
    while (top != -1) {
        postfix[j++] = stack[top--];
    }

    // Null-terminate the postfix expression
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    // Input infix expression
    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    // Output postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}