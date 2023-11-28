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

// Function to insert a new node after a node with a specific data value
void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }

    prevNode->next = newNode;
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

    // Add nodes to the doubly linked list
    int nodesToAdd;
    printf("Enter the number of nodes to add: ");
    scanf("%d", &nodesToAdd);

    for (int i = 0; i < nodesToAdd; ++i) {
        int data;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    // Print the original list
    printf("\nOriginal list:\n");
    printList(head);

    // Insert a new node after a node with a specific data value
    int dataToInsert, dataAfter;
    printf("\nEnter the data value to insert: ");
    scanf("%d", &dataToInsert);

    printf("Enter the data value after which to insert: ");
    scanf("%d", &dataAfter);

    struct Node* current = head;
    while (current != NULL && current->data != dataAfter) {
        current = current->next;
    }

    if (current != NULL) {
        insertAfter(current, dataToInsert);
    } else {
        printf("Node with data %d not found.\n", dataAfter);
    }

    // Print the modified list
    printf("\nList after insertion of node with data %d after node with data %d:\n", dataToInsert, dataAfter);
    printList(head);

    return 0;
}
