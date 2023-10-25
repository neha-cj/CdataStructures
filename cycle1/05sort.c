#include <stdio.h>
void insert(int marks[],int n, int m){
	int i;
	for(i=n-1;i>=0 && marks[i]<m;i--){
		marks[i+1]=marks[i];
	}
	marks[i+1]=m; 
}
void main(){
	int newMark,marks[50],n;
	printf("enter the number of entries\n");
	scanf("%d",&n);
	printf("enter the marks\n");
	for(int i=0;i<n;i++){
		scanf("%d",&marks[i]);
	}
	
	//bubble sort
	for(int i=0; i<n-1; i++){
		int fl=0;
		for(int j=0;j<n-1-i;j++){
			if(marks[j]<marks[j+1]){
				int temp=marks[j];
				marks[j]=marks[j+1];
				marks[j+1]=temp;
				fl=1;
			}
		}
		if(fl==0){
			break;
		}
	}
	printf("sorted marks in descending order\n");
	for(int i=0;i<n;i++){
		printf("%d ",marks[i]);
	}
	
	printf("\nenter the newmark to be inserted\n");
	scanf("%d",&newMark);
	
	
	printf("original marks: ");
	for(int i=0;i<n;i++){
		printf("%d ",marks[i]);
	}
	printf("\n");
	
	insert(marks,n,newMark);
	n++; //increase size of array
	
	printf("updated Marks: ");
	for(int i=0;i<n;i++){
		printf("%d ",marks[i]);
        }
        printf("\n");
       
}
