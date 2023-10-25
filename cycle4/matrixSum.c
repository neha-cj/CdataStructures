#include<stdio.h>
void rowsum(int r, int c,int a[][10]);
void columnsum(int r, int c,int b[][10]);



void main()
{
	int a[10][10],r,c,sumr=0,sumc=0,i,j;
	printf("Enter the no of rows and coulmns:");
	scanf("%d%d",&r,&c);
	printf("enter the mtarix:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{	
			scanf("%d",&a[i][j]);
		}
	}
	printf("Matrix:\n");
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{	
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	rowsum(r,c,a);
	printf("******************");
	columnsum(r,c,a);
	
	
}
void rowsum(int r, int c,int a[][10])
{
	int sumr=0,i,j;
	for(i=0;i<r;i++)
	{
		sumr=0;
		for(j=0;j<c;j++)
		{
			sumr=sumr+a[i][j];
		}
		printf("sum of row %d=%d\n",i+1,sumr);	
	}
}
void columnsum(int r, int c,int b[][10])
{
	int sumc=0,i,j;
	for(j=0;j<c;j++)
	{
		sumc=0;
		for(i=0;i<r;i++)
		{
			sumc=sumc+b[i][j];
		}
		printf("sum of column %d=%d\n",j+1,sumc);	
	}
}
