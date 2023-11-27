#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next,*prev;
};

void insertFront(struct node**head, int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=*head;
    
    if(*head!=NULL){
        (*head)->prev=newnode;
    }
    *head=newnode;
}
    
void traverse(struct node*head){
    while(head!=NULL){
        printf("%d <-> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

int main(){
    struct node*head =NULL;
    int i,n;
    printf("enter the number of elements");
    scanf("%d",&n);
    printf("enter elements");
    int data;
    
    for(i=0;i<n;i++){
        scanf("%d",&data);
        insertFront(&head,data);
    }
    printf("the doubly linked list is");
    traverse(head);
    return 0;
}
