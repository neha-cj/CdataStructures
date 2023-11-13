#include <stdio.h>
#include <string.h>

#define MAX 100

void reverseString(char str[]) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        // Swap characters at start and end indices
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int isPalindrome(char str[]) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return 0; // Not a palindrome
        }

        start++;
        end--;
    }

    return 1; // Palindrome
}

int main() {
    char input[MAX];

    printf("Enter a string: ");
    scanf("%s", input);

    // Reverse the string
    reverseString(input);

    // Check if it is a palindrome
    if (isPalindrome(input)) {
        printf("The reversed string is: %s\n", input);
        printf("It is a palindrome.\n");
    } else {
        printf("The reversed string is: %s\n", input);
        printf("It is not a palindrome.\n");
    }

    return 0;
}
