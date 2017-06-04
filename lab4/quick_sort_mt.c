#include<stdio.h>
#include<stdlib.h>

int count=0;
void quick_sort(int a[], int p, int r);
int partition(int a[], int p, int r);

int main(){
	int i,*a,p,r;
	FILE *fp1;
	fp1 = fopen("test_array.txt","r");
	fscanf(fp1,"%d",&r);
	
	a = (int*)malloc(r*sizeof(int));
	r += 1;
	for(i=1;i<r;i++)
		fscanf(fp1,"%d",&a[i]);
		
	fclose(fp1);
	
	p = 1;
	quick_sort(a,p,r);
	
	fp1 = fopen("output_mt.txt","w");
	for(i=1;i<r;i++){
		fprintf(fp1,"%d\n",a[i]);
	}
	fprintf(fp1,"No. of steps = %d \n",count);
	free(a);
	fclose(fp1);
	
	return 0;
}

void quick_sort(int a[], int p, int r){
	int q;
	if(p<r){
		count++;
		q = partition(a,p,r);
		count++;
		quick_sort(a,p,q-1);
		count++;
		quick_sort(a,q+1,r);
		count++;
	}
}

int partition(int a[], int p, int r){
	int x,i,j,temp;
	int mid = (p+r)/2;
	temp = a[r];
	a[r] = a[mid];
	a[mid] = temp;
	x = a[r];
	i = p-1;
	for(j=p;j<r;j++){
		count++;
		if(a[j]<=x){
			count++;
			i += 1;
			count++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			count++;
		}
	}
	temp = a[i+1];
	a[i+1] = a[r];
	a[r] = temp;
	count++;
	return i+1;
}
