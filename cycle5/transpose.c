#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a[10][10],i,j,m,n,sizem=0,sizen=0;
	printf("Enter the no of rows and columns : ");
	scanf("%d%d",&m,&n);
	printf("\nEnter the elements of the matrix : \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nOrginal matrix\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==0)
				sizem++;
			else
				sizen++;
		}
	}
	if(sizem>sizen)
		printf("They are Sparse Matrices\n");
	else
	{
		printf("They are not sparse matrices\n");
		exit(0);
	}
	printf("Transpose of the sparse matrix is:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d\t",a[j][i]);
		}
		printf("\n");
	}
	
	
}
