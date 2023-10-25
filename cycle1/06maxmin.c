#include <stdio.h>
void findLocalMaxima(int arr[],int n){
	if(n<3){
		printf("there are no local maxima in the array\n");
	  	return;
	}
	printf("Local Maximums: ");
	for(int i=1;i<n-1;i++){
		if( arr[i]>arr[i-1] && arr[i]>arr[i+1]){
			printf("%d\t",arr[i]);
		}
	}
	if(arr[0]>arr[1]){
		printf("%d\t",arr[0]);
	}
	if(arr[n-1]>arr[n-2]){
		printf("%d\t",arr[n-1]);
	}
}
int main(){
	int arr[50],n;
	printf("enter the number of elements in the array\n");
	scanf("%d",&n);
	printf("enter the elements in array\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	findLocalMaxima(arr,n);
	return 0;
}
