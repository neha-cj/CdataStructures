 //Search for a given element and print it's position.
 #include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node at the end of the linked list
void append(struct Node** head, int newData) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Set the data of the new node
    newNode->data = newData;
    
    // Set next of the new node to NULL, as it will be the last node
    newNode->next = NULL;
    
    // If the linked list is empty, make the new node as the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Traverse to the last node
    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    
    // Change the next of the last node to the new node
    last->next = newNode;
}

// Function to search for an element and print its position
void searchAndPrintPosition(struct Node* head, int searchData) {
    // Initialize variables to track the position and current node
    int position = 1;
    struct Node* current = head;

    // Traverse the list to find the element
    while (current != NULL) {
        if (current->data == searchData) {
            printf("Element %d found at position %d.\n", searchData, position);
            return;
        }
        current = current->next;
        position++;
    }

    // If the element is not found
    printf("Element %d not found in the linked list.\n", searchData);
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
    // Initialize an empty linked list
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
        append(&head, data);
    }
    
    // Print the original linked list
    printf("Original Linked List: ");
    printList(head);

    // Get user input for the element to search
    int searchData;
    printf("\nEnter the element to search: ");
    scanf("%d", &searchData);

    // Search for the element and print its position
    searchAndPrintPosition(head, searchData);
    
    return 0;
}

