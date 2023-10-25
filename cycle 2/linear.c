#include <stdio.h>
int linearSearch(int arr[],int n,int key){
	for(int i=0;i<n;i++){
		if(arr[i]==key){
			return i;
		}
	}
	return -1;
}
int main(){
	int n,k;
	printf("enter no of elements in array");
	scanf("%d",&n);
	int arr[n];
	printf("enter array elements");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("enter the element to search");
	scanf("%d",&k);
	int result=linearSearch(arr,n,k);
	if(result!=-1){
		printf("element found at index %d\n",result);
	}
	else{
		printf("element not found");
	}
	return 0;
}
