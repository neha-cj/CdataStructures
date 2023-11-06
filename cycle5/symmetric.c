#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a[10][10],i,j,m,n,sizem=0,sizen=0;
	printf("Enter the no of rows and columns : ");
	scanf("%d%d",&m,&n);
	printf("Enter the elements of the matrix : \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Orginal matrix\n");
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
			{
				sizem++;
			}	
			else
			{
				sizen++;
			}	
		}
	}
	if(sizem>sizen)
	{
		printf("They are Sparse Matrices\n");
	}	
	else
	{
		printf("They are not sparse matrices");
		exit(0);
	}
	int count=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]!=a[j][i])
			{
				count++;
				break;
			}
		}
	}
	if(count==0)
	{
		printf("It is symmetric\n");
	}	
}

