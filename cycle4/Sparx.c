#include<stdio.h>
void main()
{
	int a[10][10],i,n,m,count=0,j,b[100];
	printf("enter the no of rows and columns:\n");
	scanf("%d%d",&m,&n);
	printf("enter the matrix:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("MATRIX:\n");
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
			if(a[i][j]!=0)
			{
			printf("%d is found at row:%d and column:%d\n",a[i][j],i+1,j+1);
			count++;
			}
		}
	}
	printf("\ncount=%d",count);
	
	
}
