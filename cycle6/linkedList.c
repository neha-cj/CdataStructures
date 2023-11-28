//Create a linked list with n elements by adding elements at the end
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node*next;
};


// Function to insert a node at the end of a linked list

struct Node* insertAtEnd(struct Node* head, int newData) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (head == NULL) {
        head = newNode;
    } else {
        // Traverse to the end of the list
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        // Insert the new node at the end
        current->next = newNode;
    }

    // Return the head of the updated list
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d--> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;
    
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    
    for(int i=0; i<n;i++){
    	int data;
    	printf("enter element %d:",i+1);
    	scanf("%d",&data);
    	head = insertAtEnd(head, data);
    }

    
    

    // Print the linked list
    printf("Linked List after Insertion at the End: ");
    printList(head);
    
    return(0);
    }
