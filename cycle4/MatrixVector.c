#include<stdio.h>
void main()
{
	int a[10][10],vec[100],r,c,i,j,n,res[100];
	printf("enter the no of rows and coulumns:");
	scanf("%d%d",&r,&c);
	printf("enter the mattrix\n:");
	for(i=0;i<r;i++)
	{
		 for(j=0;j<c;j++)
		 {
		 	scanf("%d",&a[i][j]);
		 }
	}
	printf("Matrix\n:");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	printf("enter the no of terms in the vector:");
	scanf("%d",&n);
	if (c==n){
		printf("enter the elements of vector");
		for(i=0;i<n;i++){	
			scanf("%d\t",&vec[i]);
		}
	
	
		for(i=0;i<r;i++){     
			res[i]=0;
			for(j=0;j<c;j++){
		    		res[i]=res[i]+vec[j]*a[i][j];
	       		}
		}
		
		printf("the resulting vector is\n");
		for(i=0;i<r;i++)
		{
			printf("%d\t",res[i]);
			if (i<r-1){
			printf(", ");
			}
		}
		printf("\n");
	}
	else{
		printf("the matrix multiplication is not possible")
	}
}
