#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertBefore(struct Node** head, struct Node* targetNode, int data) {
    if (*head == NULL || targetNode == NULL) {
        printf("Invalid parameters.\n");
        return;
    }

    struct Node* newNode = createNode(data);

    if (*head == targetNode) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current != NULL && current->next != targetNode) {
            current = current->next;
        }

        if (current == NULL) {
            printf("Target node not found in the list.\n");
            free(newNode);
            return;
        }

        newNode->next = targetNode;
        current->next = newNode;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* nextNode = head->next;
        free(head);
        head = nextNode;
    }
}

int main() {
    struct Node* head = NULL;

    int n, element;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        if (head == NULL) {
            head = createNode(element);
        } else {
            struct Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = createNode(element);
        }
    }

    printf("Original Linked List: ");
    printList(head);

    int dataToInsert, nodeDataToInsertBefore;
    printf("Enter the data to be inserted: ");
    scanf("%d", &dataToInsert);

    printf("Enter the data of the node before which to insert: ");
    scanf("%d", &nodeDataToInsertBefore);

    struct Node* nodeToInsertBefore = head;
    while (nodeToInsertBefore != NULL && nodeToInsertBefore->data != nodeDataToInsertBefore) {
        nodeToInsertBefore = nodeToInsertBefore->next;
    }

    insertBefore(&head, nodeToInsertBefore, dataToInsert);

    printf("Linked List after Insertion: ");
    printList(head);

    freeList(head);

    return 0;
}
