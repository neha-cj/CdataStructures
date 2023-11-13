#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char item[]) {
    if (top >= MAX - 1) {
        printf("Stack Overflow.\n");
        exit(1);
    }
    strcpy(stack[++top], item);
}

void pop(char result[]) {
    if (top < 0) {
        printf("Stack Underflow.\n");
        exit(1);
    }
    strcpy(result, stack[top--]);
}

int is_operator(char symbol) {
    return (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-');
}

void postfix_to_infix(char postfix[], char infix[]) {
    int i, operandCount = 0;
    char operand[MAX], op1[MAX], op2[MAX];
    
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            operand[0] = postfix[i];
            operand[1] = '\0';
            push(operand);
            operandCount++;
        } else if (is_operator(postfix[i])) {
            pop(op2);
            pop(op1);
            sprintf(operand, "(%s%c%s)", op1, postfix[i], op2);
            push(operand);
            operandCount--;
        }
    }

    if (operandCount == 1) {
        pop(infix);
    } else {
        printf("Invalid Postfix Expression.\n");
        exit(1);
    }
}

int main() {
    char postfix[MAX], infix[MAX];
    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);
    postfix_to_infix(postfix, infix);
    printf("Infix Expression: %s\n", infix);
    return 0;
}
