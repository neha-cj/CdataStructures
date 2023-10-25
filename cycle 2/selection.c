#include<stdio.h>
void selectionSort(int a[],int n){
	int i,j,temp,min_i;
	for(i=0;i<n-1;i++){
		min_i=i;
        	for(j=i+1;j<n;j++){
            		if(a[j]<a[min_i]){
                       		min_i=j;
            		}
        	}
        	if(min_i!=i){ 
        		temp=a[i];
        		a[i]=a[min_i];
        		a[min_i]=temp;
        	}
 	}
}

int main(){
	int n,i;
	printf("Enter size of the array: ");
	scanf("%d",&n);
	int a[n];

	printf("Enter %d elements: ",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	selectionSort(a,n);

	printf("Sorted elements: ");
	for(i=0;i<n;i++)
		printf(" %d",a[i]);


return 0;
} 
