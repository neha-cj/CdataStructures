include<stdio.h>
void main()
{
	int n,a[10][10],i,j,r,c,count=0,b[10][10],flag=0,sum=0,edge;
	printf("Enter the no of nodes in the graph:");
	scanf("%d",&n);
	printf("enter the adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("ADJACENCY MATRIX:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	
	//checking if the diagonal elements are equal to 0
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				if(a[i][j]==0)
				count++;
			}
		}
	}
	if(count==n)
	{
		printf("DIAGONAL ELEMENTS ARE EQUAL\n");
	}
	
	//cheching if the matrix is symmetric

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			b[j][i]=a[i][j];
		}
	}
	flag=0;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(b[j][i]!=a[i][j])
			{
			flag=1;
			break;
			}
		}
	}
	if(flag==0)
	{
		printf("THE MATRIX IS SYMMETRIC\n");
	}
	
	//finding the nodes
	int degree[n];
	for(i=0;i<n;i++)
	{
		degree[i]=0;
		 for(j=0;j<n;j++)
		 {
		 	degree[i]=degree[i]+a[i][j];	
		 }
		 
	}
	printf("DEGREE OF EACH NODE:\n");//finding the no of sides each node is attached to
	for(i=0;i<n;i++)
	{
		 printf("NODE %d = %d\n",i+1,degree[i]);
	}
	
	//finding the edges of the graph
	for(i=0;i<n;i++)
	{
		sum=sum+degree[i];	
	}
	edge=sum/2;
	printf("\nEDGES=%d",edge);
	
	
	
	
	
	
	}
	
	
}



