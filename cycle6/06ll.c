//Delete a node given the position.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
void insertNode(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to delete a node at a given position in the linked list
void deleteNodeAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("Linked list is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the node to be deleted is the head
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Traverse to the node at position
    for (int i = 0; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    // If the position is invalid
    if (temp == NULL) {
        printf("Invalid position. Cannot delete.\n");
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL; // Initialize an empty linked list

    // Take input for the linked list
    int n, data;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertNode(&head, data);
    }

    // Print the original linked list
    printf("Original linked list: ");
    printList(head);

    // Take input for the position to delete a node
    int position;
    printf("Enter the position to delete a node: ");
    scanf("%d", &position);

    // Delete the node at the specified position
    deleteNodeAtPosition(&head, position);

    // Print the updated linked list
    printf("Updated linked list: ");
    printList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}



