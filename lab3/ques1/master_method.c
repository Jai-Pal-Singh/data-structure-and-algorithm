/*
WAP TO IMPLEMENT MASTER'S METHOD.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void master_method(float a,float b,float c);

int main(){
	float a,b,c;
	FILE *fp;
	fp = fopen("input.txt","r");
	fscanf(fp,"%f %f %f",&a,&b,&c);
	fprintf(fp,"a = %.2f, b = %.2f, c = %.2f\n",a,b,c);
	fclose(fp);
	master_method(a,b,c);
	return 0;
}

void master_method(float a,float b,float c){
	float res = (int)(log(a)/log(b));
	FILE *fp;
	fp = fopen("output.txt","w");
	fprintf(fp,"case1: n^(log(a)/log(b)) > n^c)\n");
	fprintf(fp,"case2: n^(log(a)/log(b)) = n^c)\n");
	fprintf(fp,"case3: n^(log(a)/log(b)) < n^c)\n");
	if(!(a>=1) || !(b>1)){
		fprintf(fp,"Invalid values . Please enter correct values.\n");
		exit(0);
		}
	if( res > c){
		fprintf(fp,"case1 is applicable\n");
		fprintf(fp,"Complexity is order of O(n^%.2f)\n",res);
		}
	else if( res < c){
		fprintf(fp,"case3 is applicable\n");
		fprintf(fp,"Complexity is order of O(n^%.2f)\n",c);
		}
	else if( res == c){
		fprintf(fp,"case2 is applicable\n");
		fprintf(fp,"Complexity is order of O(log(n)*n^(%.2f))\n",c);
		}
	fclose(fp);
	}
