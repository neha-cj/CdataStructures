#include <stdio.h>
int rotate(int a[],int n,char d,int cr){
	int last, first;
	if(d =='r'){
		for(int i=0;i<cr;i++){
			int last=a[n-1];
			for(int i=n-2;i>=0;i--){
				a[i+1]=a[i];
		   	}
			a[0]=last;
		}
	}
	if(d =='l'){
		for(int i=0;i<cr;i++){
			int first=a[0];
			for(int i=0;i<n-1;i++){
				a[i]=a[i+1];
			}
			a[n-1]=first;
		}
	}
	printf("output\n");
	for(int i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	
}
void main(){
	int a[50],n,cr;
	char d;
	printf("enter l for roatating left and r for roatating right\n");
	scanf("%c",&d);
	printf("enter the number o0f elements\n");
	scanf("%d",&n);
	printf("enter the array elements\n");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("enter no of times to rotate\n"); 
	scanf("%d",&cr);
	rotate(a,n,d,cr);
	
}
			
