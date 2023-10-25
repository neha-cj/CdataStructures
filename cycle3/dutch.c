#include<stdio.h>
void main()
{
	int a[20],m0[20],m1[20],m2[20],k0=0,k1=0,k2=0,c,i,n;
	printf("Enter the no of elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the element %d : ",i+1);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			m0[k0]=a[i];
			k0++;
		}
		if(a[i]==1)
		{
			m1[k1]=a[i];
			k1++;
		}
		if(a[i]==2)
		{
			m2[k2]=a[i];
			k2++;
		}
	}
	printf("\nThe array with 0s : ");
	for(i=0;i<k0;i++)
	{
		printf("%d\t",m0[i]);
	}
	printf("\nThe array with 1s : ");
	for(i=0;i<k1;i++)
	{
		printf("%d\t",m1[i]);
	}
	printf("\nThe array with 2s : ");
	for(i=0;i<k2;i++)
	{
		printf("%d\t",m2[i]);
	}
	
	for(i=0;i<k0;i++)
		a[i]=m0[i];
	c=i;
	for(i=0;i<k1;i++)
	{
		a[c]=m1[i];
		c++;
	}
	printf("\nThe array \n");
	for(i=0;i<k1;i++)
	{
		a[c]=m2[i];
		c++;
	}
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
