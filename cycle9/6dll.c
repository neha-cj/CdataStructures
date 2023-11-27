//Delete a node, given the key data value.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next, *prev;
};

void insertEnd(struct Node** head,int data){
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next=NULL;
	if(*head ==NULL){
		newNode->prev =NULL;
		*head=newNode;
		return;
	}
	
	struct Node* last =*head;
	while(last->next !=NULL){
		last=last->next;
	}
	
	last->next=newNode;
	newNode->prev=last;
}

void deleteNodeByKey(struct Node** head,int key){
	if(*head ==NULL){
	printf("List is empty.\n");
	return;
	}
	struct Node* current = *head;
	
	//search for the node with given key
	while(current !=NULL && current-> data!=key){
		current=current->next;
	}
	
	//if not found
	if(current == NULL){
		printf("Node with value %d not found\n",key);
		return;
	}
	
	//update pointers to skip node with key
	if (current->prev!=NULL){
	current->prev->next=current->next;
	}
	else{
	*head=current->next;
	}
	
	if(current->next!=NULL){
	current->next->prev = current->prev;
	}
	
	//free memory of node with key
	free(current);
}



void traverse(struct Node* head) {
    
    while (head != NULL) {
        printf("%d<--->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    int n;
    printf("Enter the number of nodes ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    	int data;
    	printf("enter data for node %d  : ",i+1);
    	scanf("%d",&data);
    	insertEnd(&head,data);
    }
    printf("Original Doubly Linked List: ");
    traverse(head);
    int keytoDelete;
    printf("enter the key value you want to delete\n");
    scanf("%d",&keytoDelete);

    deleteNodeByKey(&head, keytoDelete ); 

    printf("Doubly Linked List after deletion: ");
    traverse(head);

    return 0;
}


