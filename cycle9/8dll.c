#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node*prev;
	struct Node*next;
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

void deleteSmallest(struct Node**head){
	if(*head == NULL){
		printf("List is empty\n");
	  	return;
	}
	struct Node*current =*head;
	struct Node*smallestNode = *head;
	
	while(current!=NULL){
		if(current->data < smallestNode->data){
			smallestNode= current;
		}
		current = current->next;
	}
	
	if(smallestNode->prev !=NULL){
		smallestNode->prev->next= smallestNode->next;
	}
	else{
		*head=smallestNode->next;
	}
	
	if(smallestNode-> next!=NULL){
		smallestNode->next->prev=smallestNode->prev;
	}
	
	free(smallestNode);
}

void printList(struct Node*head){
	while (head!=NULL){
		printf("%d <-> ",head->data);
		head=head->next;
	}
	printf("NULL\n");
}

int main(){
	struct Node*head=NULL;
	
	insertEnd(&head,3);
	insertEnd(&head,8);
	insertEnd(&head,1);
	insertEnd(&head,7);
	
	printf("original list:\n");
	printList(head);
	
	deleteSmallest(&head);
	printf("List After Deleting smallest node\n");
	printList(head);
	
	return 0;
	
}
	
