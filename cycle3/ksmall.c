#include <stdio.h>

int partition(int arr[],int low,int high){
	int pivot=arr[high];
	int i=(low-1);
	for(int j= low; j<=high-1;j++){
		if(arr[j]<pivot){
			i++;
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	int temp = arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
	return(i+1);
}
int quickSelect(int arr[],int low,int high,int k){
	if(low==high){
		return arr[low];
	}
	int pivotIndex = partition(arr,low,high);
	if(k==pivotIndex){
		return arr[pivotIndex];
	}else if(k<pivotIndex){
		return quickSelect(arr,low,pivotIndex-1,k);
	}else{
		return quickSelect(arr,pivotIndex+1,high,k);	
	}
}

int main(){
	int n;
	printf("enter the number of elements in the array: ");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements\n");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int k;//change this value and find kth smallest
	printf("enter which smallest element(k value)");
	scanf("%d",&k);
	int kthsmallest = quickSelect(a,0,n-1,k-1);//adjust k by subtracting 1 for zero based index
	
	printf("The %d smallest element is :%d\n",k,kthsmallest);
	return 0;
}
	
	
	
	
	
	
