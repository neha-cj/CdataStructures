#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a[10][10],b[10][10],c[10][10],m1,n1,m2,n2,i,j,size1m=0,size1n=0,size2m=0,size2n=0;
	printf("Enter rows and columns of 1st matrix : ");
	scanf("%d%d",&m1,&n1);
	printf("Enter rows and columns of 2nd matrix : ");
	scanf("%d%d",&m2,&n2);
	printf("Enter the elements of 1st matrix :");
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the elements of 2nd matrix :");
	for(i=0;i<m2;i++)
	{
		for(j=0;j<n2;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	printf("\nFIRST MATRIX \n");
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\nSECOND MATRIX \n");
	for(i=0;i<m2;i++)
	{
		for(j=0;j<n2;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	printf("\n\nCheck whether both the matrices are sparse matrices : ");
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
		{
			if(a[i][j]!=0)
				size1m++;
			else
				size1n++;
		}
	}
	printf("\nThe no of zero elements : %d",size1n);
	printf("\nThe no of non-zero elements : %d",size1m);
	printf("\n\n");
	for(i=0;i<m2;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(a[i][j]!=0)
				size2m++;
			else
				size2n++;
		}
	}
	printf("The no of zero elements : %d\n",size2n);
	printf("The no of non-zero elements : %d\n",size2m);
	if(size1n>size1m&&size2n>size2m)
		printf("They are sparse matrices\n");
	else
	{
		printf("They are not sparse matrices\n");
		exit(0);
	}
	printf("Sum of matrices : \n");
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
}

