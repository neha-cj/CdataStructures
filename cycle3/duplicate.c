#include <stdio.h>
int main(){
	int n;
	printf("enter the number of elemets: ");
	scanf("%d",&n);
	
	printf("enter the elements\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("sorted list:\n");
	for(int i=0;i<n;i++){
	printf("%d",arr[i]);
	}
	printf("\n");
	int count=1;
	for(int i=0;i<n-1;i++){
  		if(arr[i]==arr[i+1]){
			count++;
		}
		else{
			printf("element %d occurs %d times\n",arr[i],count);
			count=1;
		}
	}	
	printf("element %d occurs %d times\n",arr[n-1],count);
}
