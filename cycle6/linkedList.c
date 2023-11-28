#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a node at the end of the doubly linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to create a doubly linked list with n elements
struct Node* createDoublyLinkedList(int n) {
    struct Node* head = NULL;

    for (int i = 0; i < n; ++i) {
        int data;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    return head;
}

// Example usage
int main() {
    int n;

    // Get the number of elements from the user
    printf("Enter the number of elements in the doubly linked list: ");
    scanf("%d", &n);

    // Create a doubly linked list with n elements
    struct Node* head = createDoublyLinkedList(n);

    // Print the created list
    printf("\nDoubly linked list with %d elements:\n", n);
    printList(head);

    return 0;
}
