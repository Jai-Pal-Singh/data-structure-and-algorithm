/*
WAP TO CALCULATE THE FOLLOWING FOR BINARY TREE:
        	a.DEPTH/HEIGHT
        	b.TOTAL NODES IN TREE
        	c.LEAF NODE
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(void){
	int i,j,n,height,num=0,level=0,*a;
	FILE *fp;
	fp=fopen("input.txt","r");
	fscanf(fp,"%d",&n);
	height=(int)(log(n+1)/log(2));
	for(i=0;i<n;level++)
	{
		for(j=0;( j<( pow(2,level) ) && i<n );j++)
		{
			fscanf(fp,"%d",&a[i]);
			i++;
		}
		
	}
	fclose(fp);
	
	fp=fopen("output.txt","w");
	
	fprintf(fp,"Tree Height : %d\n",height);
	fprintf(fp,"Levels of Tree : %d\n",level-1);
	for(;level>=0;)	
	{
		num = num+( pow(2,(level-2)) ); 
		level--;
	}
	fprintf(fp,"Elements in leaf node : %d",n-num);
	
	fclose(fp);		
}
