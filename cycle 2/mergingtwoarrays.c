#include <stdio.h>
void mergeArrays(int A[],int n,int B[],int m,int C[]){
	int i=0,j=0,k=0;
	while(i<n && j<m){
		if(A[i]<=B[j]){
			C[k]=A[i];
			i++;
		}
		else{
			C[k]=B[j];
			j++;
		}
		k++;
	}
	while(i<n){
		C[k] =A[i];
		i++;
		k++;
       	}
       	while(j<m){
       		C[k] = B[j];
       		j++;
       		k++;
       	}
}
int main(){
        int n,m;
        printf("enter the no of elements in arrays A and B\n");
        scanf("%d %d",&n,&m);
        int A[n],B[m];
        printf("enter the sorted array A: ");
        for(int i=0;i<n;i++)
        	scanf("%d",&A[i]);
        printf("enter the sorted array B: ");
        for(int i=0;i<m;i++)
        	scanf("%d",&B[i]);
	int C[m+n];
	mergeArrays(A,n,B,m,C);
	printf("Merged Array C: ");
	for(int i=0;i<n+m;i++){
		printf("%d ",C[i]);
	}
	printf("\n");
	return 0;
}
