


#include<stdio.h>

#include<stdlib.h>

struct node

{

int data;

int avail;

struct node *llink,*rlink;

}*first=NULL,*last=NULL,*temp=NULL,*t=NULL;

void create()

{

temp=(struct node*)malloc(sizeof(struct node));

printf("Enter data:");

scanf("%d",&temp->data);

temp->avail=1;

temp->llink=NULL;

temp->rlink=NULL;

if(first==NULL)

{

first=temp;

last=temp;

}

else

{

last->rlink=temp;

temp->llink=last;

last=temp;

}

}

void display()

{

temp=first;

printf("NULL");

while(temp!=NULL)

{

printf(" %d:%d<---->",temp->data,temp->avail);

temp=temp->rlink;

}

printf(" NULL\n");

}

void allocate()

{

int size,newdata;

printf("Enter size\n");

scanf("%d",&size);

temp=first;

while(temp!=NULL)

{

if(temp->data>=size && temp->avail==1)

   break;

temp=temp->rlink;

}

if( temp==NULL)

  printf("cannot allocate\n");

else if (temp->data==size)

  temp->avail=0;

 else

   {newdata=temp->data-size;

    temp->data=size;

    temp->avail=0;

    t=(struct node*)malloc(sizeof(struct node));

    t->data=newdata;

    t->avail=1;

    t->llink=temp;

    t->rlink=temp->rlink;

    t->llink=temp;

    temp->rlink=t;

   }

}

void garbagecollect()

{

 temp=first;

 int pos[100],p=1,i=0,j,tp;

 char ch;

    while(temp!=NULL)

    {

     if(temp->avail==0)

      {pos[i]=p;i++;}

     p++; 

     temp=temp->rlink;

    }

    printf("list of allocated positions.... \n");

    tp=--i;

 for(i=tp;i>=0;i--)

  {printf("%d-->",pos[i]);}

 for(i=0;i<=tp;i++)

  {

    printf("want to free...%d\n..enter y if yes::",pos[i]);

    ch=getchar();

    scanf("%c",&ch);

   if(ch=='y')

    {

        temp=first;

    for(j=1;j<pos[i];j++)

    {

    temp=temp->rlink;

    }

    temp->avail=1;

    } // end of choice

}//end of for

}

void main()

{

int ch;

do

{

printf("\nMenu\n----\n1. Create AVAIL List\n2.Display\n3.Allocate\n4.garbagecollect\n5.Exit\n");

printf("\nEnter the choice:");

scanf("%d",&ch);

switch(ch)

{

case 1:

    create();

    display();

    break;

case 2:

    display();

    break;

case 3:

     allocate();

     break;

case 4:

     garbagecollect();

     break;

case 5:

    exit(0);

default:

    printf("There is no such operation:\n");

}

}

while(1);

}




