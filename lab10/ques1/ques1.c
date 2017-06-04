/* Using matrix write a program to 
	1. count the number of self loops in a graph
	2. compute the indegree and outdegree of the given graph
	3. find out the number of isolated nodes in a graph
 */
#include<stdio.h>
#include<stdlib.h>

void self_loop(int *arr[], int V);
void outdegree(int *arr[], int V);
void indegree(int *arr[], int V);
void isolated_node(int *arr[], int V);

int main(void){
	int V,i,j;
	FILE *fp;
	fp = fopen("input.txt","r");
	fscanf(fp,"%d",&V);

	int **arr = (int **)malloc((V+1)*sizeof(int *));
	for(i=1;i<=V;i++)
        arr[i] = (int *)malloc((V+1)*sizeof(int));
	for(i=1;i<=V;i++){
		for(j=1;j<=V;j++){
			fscanf(fp,"%d",&arr[i][j]);
			}
		}
	self_loop(arr,V);
	outdegree(arr,V);
	indegree(arr,V);
	isolated_node(arr,V);
	free(arr);
	fclose(fp);
	return 0;
	}

void self_loop(int *arr[], int V){
	int i,count=0;
	for(i=1;i<=V;i++)
		if(arr[i][i]==1)
			count++;
	printf("Number of Self Loops in the Graph : %d\n\n",count);
	}

void outdegree(int *arr[], int V){
	int i,j,count;
	for(i=1;i<=V;i++){
		count = 0;
		for(j=1;j<=V;j++)
			if(arr[i][j] == 1)
				count++;
		printf("Outdegree of Vertex %d = %d\n",i,count);
	}
	printf("\n");
}

void indegree(int *arr[], int V){
	int i,j,count;
	for(j=1;j<=V;j++){
		count = 0;
		for(i=1;i<=V;i++)
			if(arr[i][j] == 1)
				count++;
		printf("Indegree of Vertex %d = %d\n",j,count);
	}
	printf("\n");
}

void isolated_node(int *arr[], int V){
	int i,j,indegree[V], outdegree[V],isolated=0;
	for(i=1;i<=V;i++){
		indegree[i] = 0;
		outdegree[i] = 0;
	}
	
	for(i=1;i<=V;i++){
		for(j=1;j<=V;j++)
			if(arr[i][j] == 1)
				outdegree[i]++;
	}
	for(j=1;j<=V;j++){
		for(i=1;i<=V;i++)
			if(arr[i][j] == 1)
				indegree[j]++;
	}
	for(i=1;i<=V;i++){
		if(indegree[i] == 0 && outdegree[i] == 0)
			isolated++;
	}
	printf("Number of Isolated nodes in the Graph : %d\n",isolated);
}
