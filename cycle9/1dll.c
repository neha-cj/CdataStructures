

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev,*next;
};


struct node *newnode,*head,*temp;

int main()
{
	int i,n;
	head = NULL;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode->data);
		newnode->prev = NULL;
		newnode->next = NULL;
		if(head == NULL)
		{
			head=newnode;
			temp=newnode;
		}
		else
		{
			temp->next = newnode;
			newnode->prev = temp;
			temp = newnode;
		}
	}
	printf("Created Linked List is:\n");
	temp = head;
	
	while(temp != NULL)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("\n");
	return 0;
}
