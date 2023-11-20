//Given a node data, insert a new node after it.

#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node after a given node
void insertAfter(struct Node* prevNode, int newData) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Set the data of the new node
    newNode->data = newData;

    // Set the next of the new node to the next of the previous node
    newNode->next = prevNode->next;

    // Set the next of the previous node to the new node
    prevNode->next = newNode;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function
int main() {
    // Initialize a linked list with some elements
    struct Node* head = NULL;

    // Number of elements in the linked list
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Add elements to the linked list
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);

        // Add the node at the end
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            struct Node* last = head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newNode;
        }
    }

    // Print the original linked list
    printf("Original Linked List: ");
    printList(head);
    printf("\n");

    // User input for data value and insert a new node after it
    int newData;
    printf("Enter the data value after which you want to insert a new node: ");
    scanf("%d", &newData);

    struct Node* currentNode = head;
    while (currentNode != NULL && currentNode->data != newData) {
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) {
        printf("Node with data %d not found in the linked list.\n", newData);
    } else {
        // Insert a new node after the found node
        int newElement;
        printf("Enter the data value for the new node: ");
        scanf("%d", &newElement);
        insertAfter(currentNode, newElement);

        // Print the updated linked list
        printf("Updated Linked List: ");
        printList(head);
        printf("\n");
    }

    return 0;
}


