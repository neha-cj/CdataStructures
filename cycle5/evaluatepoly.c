#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct polynomial
{
	int  coeff,expo;	
};
void main()
{
	struct polynomial p[100];
	int n,i,sum=0,x;
	
	printf("Enetr the number of terms in the polynomial:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enetr the coefficient and exponent of %dth term:",i+1);
		scanf("%d %d",&p[i].coeff,&p[i].expo);
	}
	printf("POLYNOMIAL\n");
	for(i=0;i<n;i++)
	{
		printf("%dx^%d",p[i].coeff,p[i].expo);
		if(i<n-1)
		{
			printf("+");
			
		}
	}
	printf("Enter the value of x:");
	scanf("%d",&x);
	for(i=0;i<n;i++)
	{
		sum=sum+p[i].coeff*pow(x, i);
	}
	
	//printing the value of the polynomial
	printf("%d",sum);
}
