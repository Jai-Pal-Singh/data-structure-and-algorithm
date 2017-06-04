#include<stdio.h>
#include<stdlib.h>

int main(void){
	int V,i,j;
	FILE *fp;
	fp = fopen("input.txt","r");
	fscanf(fp,"%d",&V);

	int **arr = (int **)malloc((V+1)*sizeof(int *));
	for(i=1;i<=V;i++)
        arr[i] = (int *)malloc((V+1)*sizeof(int));
	
	int **transpose = (int **)malloc((V+1)*sizeof(int *));
	for(i=1;i<=V;i++)
        transpose[i] = (int *)malloc((V+1)*sizeof(int));
	
	for(i=1;i<=V;i++){
		for(j=1;j<=V;j++){
			fscanf(fp,"%d",&arr[i][j]);
			transpose[j][i] = arr[i][j];
			}
		}

	free(arr);
	free(transpose);
	fclose(fp);
	return 0;
	}
