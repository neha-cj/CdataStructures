#include <stdio.h>
#include <string.h>

int main(){
	int i,j,n,count;
	char s[100];
	printf("enter the string in lowercase\n");
	scanf("%[^\n]",s);
	printf("frequency of letters in string\n");
	n=strlen(s);
	for(i=0;i<n;i++){
		count=1;
		if(s[i]){
			for(j=i+1;j<n;j++){
				if(s[i]==s[j]){
					count++;
					s[j]='\0';
				}
			}
			printf("'%c'=%d \n",s[i],count);
		}
	}
	return 0;
}
			
	
