#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a new node at the end of the doubly linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->prev = NULL;
        newNode->next = NULL;
        *head = newNode;
    } else {
        struct Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
        newNode->next = NULL;
    }
}

// Function to delete a node at a given position in the doubly linked list
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }

    struct Node* current = *head;
    int currentPosition = 0;

    // Traverse to the desired position
    while (currentPosition < position && current != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Position %d is beyond the length of the list. Node not deleted.\n", position);
        return;
    }

    // Adjust pointers to delete the node
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
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
        insertEnd(&head, i);
    }

    // Print the original list
    printf("Original doubly linked list:\n");
    printList(head);

    // Delete a node at position 2
    deleteAtPosition(&head, 2);

    // Print the modified list
    printf("\nDoubly linked list after deletion at position 2:\n");
    printList(head);

    return 0;
}
