#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a[10][10],b[10][10],i,j,m,n,sizem=0,sizen=0;
	float x;
	printf("Enter the no of rows and columns : ");
	scanf("%d%d",&m,&n);
	printf("\nEnter the elements of the matrix : \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter the element a[%d][%d] : ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nEntered matrix\n");
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
	int y=sizem+sizen;
	printf("\nThe no of zero elements : %d",sizem);
	printf("\nThe no of non-zero elements:%d ",sizen);
	printf("\nTotal no of elements : %d",y);
	
	if(sizem>sizen)
		printf("\nThey are Sparse Matrices\n");
	else
	{
		printf("They are not sparse matrices");
		exit(0);
	}
	int k=0;
	printf("\nIndex of non zero elements : \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]!=0)
			{
				b[k][0]=i;
				b[k][1]=j;
				b[k][2]=a[i][j];
				k++;
			}
		}
	}
	printf("\nROWS\tCOLUMNS\tVALUES\n");
	for(i=0;i<sizen;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",b[i][j]);
			
		}
		printf("\n");
		
	}
	x=(float)sizem/y;
	printf("Sparsity of the Matrix : %f",x);
}







