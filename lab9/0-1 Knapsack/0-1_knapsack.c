#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

void knapsack(int items,int capacity,int weight[],int values[]);

int main(void){
	int items,capacity,*weight,*values,i;
	FILE *fp;
	fp = fopen("input.txt","r");
	fscanf(fp,"%d %d",&items, &capacity);
	weight = (int *)malloc((items+1)*sizeof(int));
	values = (int *)malloc((items+1)*sizeof(int));
	weight[0]=0;
	values[0]=0;
	for(i=1;i<=items;i++)
		fscanf(fp,"%d %d",&weight[i],&values[i]);
	fclose(fp);
	knapsack(items,capacity,weight,values);
	free(weight);
	free(values);
	return 0;
	}
	
void knapsack(int items,int capacity,int weight[],int values[]){
	int i,m,c[items+1][capacity+1];
	for(i=0;i<=items;i++){
		for(m=0;m<=capacity;m++){
			if(i==0||m==0)
				c[i][m] = 0;
			else if(weight[i] > m)
				c[i][m] = c[i-1][m];
			else if(i>0 && weight[i] <= m)
				c[i][m] = MAX((values[i] + c[i-1][m-weight[i]]),(c[i-1][m]));
			}
		}
	printf("Max-Value : %d\n",c[items][capacity]);		
	}
