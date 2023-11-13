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

void findMaxMinAverage() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    int max = stack[top];
    int min = stack[top];
    int sum = 0;
    int count = 0;

    for (int i = top; i >= 0; i--) {
        int current = stack[i];
        sum += current;

        if (current > max) {
            max = current;
        }

        if (current < min) {
            min = current;
        }

        count++;
    }

    float average = (float)sum / count;

    printf("Max Element: %d\n", max);
    printf("Min Element: %d\n", min);
    printf("Average: %.2f\n", average);
}

int main() {
    int numElements, element;

    printf("Enter the number of elements to push onto the stack: ");
    scanf("%d", &numElements);

    printf("Enter %d elements:\n", numElements);
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &element);
        push(element);
    }

    printf("Elements in the stack:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }

    findMaxMinAverage();

    return 0;
}
