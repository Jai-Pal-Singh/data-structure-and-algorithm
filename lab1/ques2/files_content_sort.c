/*
W.A.P to sort the contents of 25 files, stored in a directory.
	-input files are having .txt and .dat extension
	-you have to pass the directory name during execution through command line.
	-store the output files with same names in different directory    
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
	int n,*m,o,i,j,k,l,temp,g;
	FILE *fp1,*fp2;
	char *a,*b,*c,str1[100] = "ls ";
	char str2[] = " > input_files.txt";
	char txt[] = ".txt";
	char dat1[] = ".dat";
	a = (char*)malloc(100*sizeof(char));
	strcat(str1, argv[1]);
	strcat(str1,str2);
	system(str1);

	if((fp1 = fopen("input_files.txt","r"))==NULL)
	{
		printf("file did not open");exit(1);
	}
	
	while(!feof(fp1)){
		fscanf(fp1,"%s",a);
		b=strstr(a,txt);
		c=strstr(a,dat1);
		if(c==NULL)
			c="c";
		if(b==NULL)
			b="b";
		char st[]="Files_Input/";
		strcat(st,a);
		if((strlen(b)==4||strlen(c)==4)&&(b!=NULL||c!=NULL)){

			fp2 = fopen(st,"r");

			fscanf(fp2,"%d",&n);

			m = (int*)malloc((n+1)*sizeof(int));

			for(j=0;j<n;j++){
				fscanf(fp2,"%d",&m[j]);
			}
			fclose(fp2);
			
			 for(j=0;j<n;++j)
			    for(l=j+1;l<n;++l)
				{
				    if(m[j]>m[l])  
					{
					   temp=m[j];
					   m[j]=m[l]; 
					   m[l]=temp;
				    }
			    }
				
			char strout[]="Output_Files/";
			strcat(strout,a);
			
			fp2 = fopen(strout,"w");
			for(j=0;j<n;j++){
				fprintf(fp2,"%d\n",m[j]);
			}
			fclose(fp2);
		}
	}
	fclose(fp1);
	return 0;
}
