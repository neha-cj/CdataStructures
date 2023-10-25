#include<stdio.h>
void main()
{
	int a[10][10],m,n,flag=0,i,j,c,min,max,k;
	printf("enter the no of rows and columns:");
	scanf("%d%d",&m,&n);
	printf("Enter the matrix:\n");
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
	flag=0;
	for(i=0;i<m;i++)
	{	
		min=a[i][0];
		c=0;
		for(j=0;j<n;j++)
		{
			if(a[i][j]<min)
			{
				min=a[i][j];
				c=j;
			}
		}
		max=a[0][c];
		for(k=0;k<m;k++)
		{
			if(a[k][c]>max)
			{
				max=a[k][c];
			}
			}
		if(max==min)
		{
			printf("saddle point=%d",min);
			flag=1;
		}
		
	}
	if(flag==0)
	{
	printf("there is no saddle point");
	}

}
	


