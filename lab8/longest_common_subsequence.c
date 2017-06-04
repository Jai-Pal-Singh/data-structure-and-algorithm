#include<stdio.h>
#include<stdlib.h>

int n=0;
void lcs_length(char x[],char y[],int m,int n);
void print_lcs(char b[][n], char x[], int i, int j);

int main(){
	int m,i;
	char *x,*y;
	FILE *fp;
	fp = fopen("input.txt","r");
	fscanf(fp,"%d%d",&m,&n);

	x = (char *)malloc((m+1)*sizeof(char));
	y = (char *)malloc((n+1)*sizeof(char));
	for(i=1;i<=m+1;i++)
	{
		fscanf(fp,"%c ",&x[i]);
	}
		x[i] ='\0';
	for(i=1;i<=n+1;i++)
		fscanf(fp,"%c ",&y[i]);
		y[i] ='\0';

	lcs_length(x,y,m,n);
	return 0;
	}

void lcs_length(char x[],char y[],int m,int n){
	char b[m][n];
	int c[m+1][n+1],i,j;
	for(i=1;i<=m;i++)
		c[i][0] = 0;
	for(j=0;j<=n;j++)
		c[0][j] = 0;
	printf("%s\n%s\n",x,y);
	for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++){
			if(x[i] == y[j]){
				c[i][j] = c[i-1][j-1]+1;
				b[i][j] = '\\';
				}
			else if(c[i-1][j] >= c[i][j-1]){
				c[i][j] = c[i-1][j];
				b[i][j] = '|';
				}
			else{
				c[i][j] = c[i][j-1];
				b[i][j] = '-';
				}
			}
		}
		for(i=0;i<=m;i++)
		{
			for(j=0;j<=n;j++){
				printf("%d ",c[i][j]);
			}
			printf("\n");
		}
	print_lcs(b,x,m,n);
	printf("\n");
	}
 void print_lcs(char b[][n], char x[], int i, int j){
	 if(i==0 || j==0)
		return ;
	if(b[i][j] == '\\'){
		print_lcs(b,x,i-1,j-1);
		printf("%c",x[i]);
		}
	else if(b[i][j] == '|')
		print_lcs(b,x,i-1,j);
	else
		print_lcs(b,x,i,j-1);
	 }
