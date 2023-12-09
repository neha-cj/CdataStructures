//How doubly linked list can be used to find palindromes ? in c
#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to check if a doubly linked list is a palindrome
int isPalindrome(struct Node* head) {
    struct Node *front = head, *back = NULL;
    struct Node*temp=head;
    // Move 'back' to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    back = temp;

    // Check for palindrome
    while (front != back && front->prev != back) {
        if (front->data != back->data) {
            return 0; // Not a palindrome
        }
        front = front->prev;
        back = back->next;
    }

    return 1; // Palindrome
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free memory allocated for the doubly linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    char input;

    // Get user input for linked list elements
    printf("Enter characters for the linked list (enter 'q' to stop): ");
    while (scanf(" %c", &input) == 1 && input != 'q') {
        insertAtEnd(&head, input);
    }

    printf("Doubly linked list: ");
    displayList(head);

    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    // Free allocated memory
    freeList(head);

    return 0;
}
