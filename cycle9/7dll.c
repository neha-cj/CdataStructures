#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};



struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }

    return newNode;
}



struct Node* deleteNode(struct Node* head, struct Node* delNode) {
    if (head == NULL || delNode == NULL) {
        printf("List is empty or node to be deleted is NULL.\n");
        return head;
    }

    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    } else {
        head = delNode->next;
    }

    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }

    free(delNode);
    return head;
}

void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d<--->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    
    head = insertAtBeginning(head, 5);
    head = insertAtBeginning(head, 4);
    head = insertAtBeginning(head, 7);
    printf("Doubly Linked List: ");
    traverse(head);

    head = deleteNode(head, head->next); // Delete the node with data 4

    printf("Doubly Linked List after deletion: ");
    traverse(head);

    return 0;
}

