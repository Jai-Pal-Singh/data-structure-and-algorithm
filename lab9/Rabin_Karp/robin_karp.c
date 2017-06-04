#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void rabin_karp(int T[],int P[],int n,int m,int d,int q);
int string_matcher(int P[],int T[],int m,int s);

int main(void){
	int n,m,i,*T,*P,d,q;
	FILE * fp;
	fp = fopen("input.txt","r");
	fscanf(fp,"%d %d %d %d",&n,&m,&d,&q);
	T = (int *)malloc((n+1)*sizeof(int));
	P = (int *)malloc((m+1)*sizeof(int));
	for(i=1;i<=n;i++)
		fscanf(fp,"%d",&T[i]);
	for(i=1;i<=m;i++)
		fscanf(fp,"%d",&P[i]);
	fclose(fp);
	rabin_karp(T,P,n,m,d,q);
	return 0;
	}
	
void rabin_karp(int T[],int P[],int n,int m,int d,int q){
	int p=0,t=0,h,i,s;
	h = ((int)(pow(d,m-1)))%q;
	for(i=1;i<=m;i++){
		p = (d*p + P[i])%q;
		t = (d*t + T[i])%q;
		}
	
	for(s=0;s<=n-m;s++){
		
		if(p==t){
			
			if(string_matcher(P,T,m,s))
				printf("Shift occurs at Shift : %d \n",s);
			
			}
		
		if(s < n-m){

			t = (d*(t - T[s+1]*h)+ T[s+m+1])%q;
			if(t<1)
				t +=13; 
			printf("s= %d, p = %d,t0 = %d\n",s,p,t);
			}
		}
	}
	
	
int string_matcher(int P[],int T[],int m,int s){
	int i;
	for(i=1;i<=m;i++)
		if(P[i]!=T[s+i]){
		
			return 0;
		}
	return 1;
	}
