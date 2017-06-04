#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int* count_sort(int a[], int n , int range);

int main(){
	int i,n,*a,range;
	FILE *fp1,*fp2;
	fp1 = fopen("input.txt","r");
	fp2 = fopen("output.txt","w");
	fscanf(fp1,"%d",&n);
	a = (int*)malloc(n*sizeof(int));
	
	for(i=1;i<=n;i++)
		fscanf(fp1,"%d",&a[i]);
	
	fclose(fp1);
	
	range = a[1];
	for(i=2;i<=n;i++){
		if(range<a[i])
		 	range = a[i];
	}

	a=count_sort(a,n,range);
	for(i=1;i<=n;i++)
		fprintf(fp2,"%d\n",a[i]);
	free(a);

	return 0;
}

int*  count_sort(int a[], int n , int range){
	int i,j,*b,*c;
	
	b = (int*)malloc(n*sizeof(int));
	c = (int*)malloc(range*sizeof(int));
	
	for(i=0;i<=range;i++)
		c[i]=0;

	for(j=1;j<=n;j++)
		c[a[j]]=c[a[j]]+1;
		
	for(i=1;i<=range;i++)
		c[i] = c[i] + c[i-1];
	
	for(j=n;j>=1;j--){
		b[c[a[j]]] = a[j];
		c[a[j]] = c[a[j]]-1;
	}
	//free(c);
	return b;
}
