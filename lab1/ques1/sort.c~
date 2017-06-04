/*
W.A.P which takes input from a file and this input is a set of integer numbers. Sort these numbers and store the output in a file.
*/
#include<stdio.h>
#include<stdlib.h>

int main(){
	int *a,b,n,i,j,k,temp;
	FILE *fp1,*fp2;
	fp1 = fopen("input.txt","r");
	fscanf(fp1,"%d",&n);
	a = (int*)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++){
		fscanf(fp1,"%d",&a[i]);
	}
	fclose(fp1);
	
	for(i=0;i<n;i++){
		k=a[i];
		b=i;
		for(j=i+1;j<n;j++){
			if(k>a[j]){
				k = a[j];
				b=j;
			}
		}		
		temp = k;
		a[b] = a[i];
		a[i] = temp;
	}
	fp2 = fopen("output.txt","w");
	for(i=0;i<n;i++){
		fprintf(fp2,"%d\n",a[i]);
	}
	fclose(fp2);
	return 0;
}
