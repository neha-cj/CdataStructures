#include <studio.h>
int binarySearch(int arr[],int n, int low,int high){
	while(low<=high){
		int mid=low+(high-low)/2;
		if(array[mid]==x){
			return mid;
		}
		if(array[mid]<x)
			low=mid+1;
		else
			high=mid-1;
		}
	return -1;
}
int main(void){
	int n,sk;
	printf("enter the no of elements");
	scanf("%d",&n);
	int arr[n];
	printf("enter the array elements");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("enter the search element");
	scanf("%d",&sk);
	int result=binarySearch(arr,sk,0,n-1);
	if (result==-1)
		printf("not found");
	else
		printf("element is found at index %d",result);
	
}
			
