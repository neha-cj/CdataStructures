#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next,*prev;
};

void insertEnd(struct node**head,int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    
    if(*head==NULL){
        newnode->prev=NULL;
        *head=newnode;
        return;
    }
    struct node*last=*head;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=newnode;
    newnode->prev=last;
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
        insertEnd(&head,data);
    }
    printf("the doubly linked list is");
    traverse(head);
    return 0;
}
