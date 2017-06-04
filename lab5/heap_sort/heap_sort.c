#include<stdio.h>
#include<stdlib.h>

int* heap_sort(int a[], int n);
void build_max_heap(int a[],int n);
void max_heapify(int a[],int i);
int heapsize;

int main(){
	int i,n,*a;
	FILE *fp1,*fp2;
	fp1 = fopen("input.txt","r");
	fp2 = fopen("output.txt","w");
	fscanf(fp1,"%d",&n);
	a = (int*)malloc(n*sizeof(int));
	for(i=1;i<=n;i++)
		fscanf(fp1,"%d",&a[i]);
	heapsize = n;
	fclose(fp1);
	a = heap_sort(a,n);
	for(i=1;i<=n;i++)
		fprintf(fp2,"%d\n",a[i]);
	fclose(fp2);
	return 0;
	}
	
int* heap_sort(int a[], int n){
	int i,temp;
	build_max_heap(a,n);
	for(i=n;i>1;i--){
		temp = a[1];
		a[1] = a[i];
		a[i] = temp;
		heapsize -= 1;
		max_heapify(a,1);
		}
	return a;
	}

void build_max_heap(int a[],int n){
	int i;
	heapsize = n;
	for(i=n/2;i>0;i--)
		max_heapify(a,i);
	}

void max_heapify(int a[],int i){
	int l,r,largest,temp;
	r = 2*i + 1;
	l = 2*i;
	if(l<=heapsize && a[l]>a[i])
		largest = l;
	else
		largest = i;
	if(r<=heapsize && a[r]>a[largest])
		largest = r;
	if(largest != i){
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		max_heapify(a,largest);
		}
	}
