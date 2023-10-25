#include <stdio.h>
double findMean(int arr[],int n){
	double sum=0;
	for(int i=0;i<n;i++){
		sum+= arr[i];
	}
	return sum/n;
}
double findMedian(int arr[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	if(n%2!=0){
		return arr[n/2];
	}
	else{
		return (arr[(n-1)/2]+arr[n/2])/2.0;
	}
}
int findMode(int arr[],int n){
	int mode=arr[0];
	int maxCount=0;
	for(int i=0;i<n;i++){
		int count=0;
		for(int j=0;j<n;j++){
			if(arr[j]==arr[i]){
				count++;
			}
		}
		if(count>maxCount){
			maxCount=count;
			mode=arr[i];
		}
	}
	return mode;
}
			
int main(){
	int a[50],n;
	printf("enter the number of elements\n");
	scanf("%d",&n);
	printf("enter the elements of array\n");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	double mean=findMean(a,n);
	double median=findMedian(a,n);
	int mode=findMode(a,n);
	
	printf("mean: %.2lf,median: %.2lf,mode:%d",mean,median,mode);
	return 0;
}
	
