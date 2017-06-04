#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int n=0;
void matrix_chain_order(int p[], int n);
void printmcm(int s[][n], int i, int j);

int main(){
	int i,*p;
	FILE *fp;
	fp = fopen("input.txt","r");
	fscanf(fp,"%d",&n);
	p = (int *)malloc(n*sizeof(int));
	for(i=1;i<=n;i++)
		fscanf(fp,"%d",&p[i]);
	matrix_chain_order(p,n);
	fclose(fp);
	return 0;
	}

void matrix_chain_order(int p[],int n){
	int i,j,k,l,q,m[n][n],s[n][n];
	for(i=1;i<n;i++)
		m[i][i] = 0;
	for(l=2;l<n;l++)
		for(i=1;i<n-l+1;i++){
			j = i + l -1;
			m[i][j] = INT_MAX;
			for(k=i;k<j;k++){
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
					}
				} 
			}
	printmcm(s,i,j);
	printf("\n");
	}

void printmcm(int s[][n], int i, int j){
	if(i==j)
		printf("A%d",i-1);
	else{
		printf("(");
		printmcm(s,i,s[i][j]);
		printmcm(s,s[i][j]+1,j);
		printf(")");
		}
	}
