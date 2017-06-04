/*find out the inversions in an array*/
#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,*a,i,j;
	FILE *fp;
	
	fp = fopen("test_array.txt","r");
	fscanf(fp,"%d",&n);
	a = (int *)malloc(n* sizeof(int *));
	
	for(i=0;i<n;i++)
		fscanf(fp,"%d",&a[i]);

	fclose(fp)	;
	fp = fopen("result_array.txt","w");
	
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				fprintf(fp,"a[%d] = %d,  a[%d] = %d\n",i,a[i],j,a[j]);
			}
		}
	}	
	fclose(fp)	;	
	return 0;
}
