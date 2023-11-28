// To insert a new node at a given position in a doubly linked list in C, you can create a function that 
//traverses the list to the desired position and then inserts the new node

#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a new node at a given position in the doubly linked list
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position <= 0) {
        // Insert at the beginning
        newNode->next = *head;
        newNode->prev = NULL;

        if (*head != NULL) {
            (*head)->prev = newNode;
        }

        *head = newNode;
    } else {
        // Traverse to the desired position
        struct Node* current = *head;
        int currentPosition = 0;

        while (currentPosition < position - 1 && current != NULL) {
            current = current->next;
            currentPosition++;
        }

        if (current == NULL) {
            printf("Position %d is beyond the length of the list. Node not inserted.\n", position);
            free(newNode);
            return;
        }

        // Adjust pointers to insert the new node
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }

        current->next = newNode;
    }
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Example usage
int main() {
    struct Node* head = NULL;

    // Insert nodes at the end of the doubly linked list
    for (int i = 1; i <= 5; ++i) {
        insertAtPosition(&head, i, i - 1);
    }

    // Print the original list
    printf("Original doubly linked list:\n");
    printList(head);

    // Insert a new node at position 2 with data 10
    insertAtPosition(&head, 10, 2);

    // Print the modified list
    printf("\nDoubly linked list after insertion at position 2:\n");
    printList(head);

    return 0;
}
