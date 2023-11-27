//given a node data, insert a new node before the specfic node 

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node*prev, *next;
};

void insertBefore(struct node** head,int targetData, int newData){
	struct node* newnode =(struct node*)malloc(sizeof(struct node));
	newnode->data=newData;
	
	if(*head==NULL){
		newnode->prev=NULL;
		newnode->next=NULL;
		*head=newnode;
		return;
	}
	struct node*current=*head;
	
	while(current!=NULL && current->data!=targetData){
		current=current->next;
	}
	
	if(current ==NULL){
		printf("node with %d data not found\n",targetData);
		free(newnode);
		return;
	}
	
	//update pointers to insert newnode before specified node
	newnode->prev =current->prev;
	newnode->next=current;
	if(current->prev!=NULL){
		current->prev->next =newnode;
	}else{
		*head=newnode;
	}
	current->prev =newnode;
}


void printList(struct node*head){
	while(head!=NULL){
	printf("%d <-> ", head->data);
	head=head->next;
        }
        printf("NULL\n");
 }
 
 int main(){
 struct node*head =NULL;
 int n;
 	printf("enter n\n" );
 	scanf("%d",&n);
 	for(int i=0;i<n;i++){
 		int data;
 		printf("enter data for node %d  :",i+1);
 		scanf("%d",&data);
 		struct node* newnode =(struct node*)malloc(sizeof(struct node));
 		newnode->data=data;
 		newnode->next=NULL;
 		
 		if(head==NULL){
 		newnode->prev=NULL;
 		head=newnode;
 		}else{
 			struct node*last =head;
 			while(last->next!=NULL){
 			last=last->next;
 			}
 			last->next =newnode;
 			newnode->prev=last;
 		}
 	}
 	printf("original list\n");
 	printList(head);
 	
 	int targetData ,newData;
 	printf("enter the target node data");
 	scanf("%d",&targetData);
 	printf("enter the new node data");
 	scanf("%d",&newData);
 	
 	insertBefore(&head,targetData,newData);
 	
 	printf("\nList after insertion\n");
 	printList(head);
 	
 	return 0;
 }
	
