#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 100

int stack[MAXSTACK];
int top = -1;

void push(int item) {
    if (top >= MAXSTACK - 1) {
        printf("Stack Overflow.\n");
        exit(1);
    }
    stack[++top] = item;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow.\n");
        exit(1);
    }
    return stack[top--];
}

void decimal_to_binary(int decimal) {
    while (decimal > 0) {
        int remainder = decimal % 2;
        push(remainder);
        decimal /= 2;
    }

    printf("Binary Equivalent: ");
    while (top >= 0) {
        printf("%d", pop());
    }
    printf("\n");
}

int main() {
    int decimal;

    printf("Enter Decimal Number: ");
    scanf("%d", &decimal);

    decimal_to_binary(decimal);

    return 0;
}
