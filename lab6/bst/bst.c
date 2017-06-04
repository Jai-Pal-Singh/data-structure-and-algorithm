/*
WAP TO IMPLEMENT BINARY SEARCH TREE.
*/
#include<stdio.h>
#include<stdlib.h>

struct bst{
	int val;
	struct bst *left,*right;
};

struct stack{
	int val;
	struct bst *p;
};

void insert_bst(int value);
void print_bst(struct bst *x);

struct bst* root;
struct stack *head;

int main(){
	int i,n,*a,input,value;
	FILE *fp1,*fp2;

	fp1 = fopen("input.txt","r");
	//fp2 = fopen("output.txt","w");
	fscanf(fp1,"%d",&n);
	a = (int*)malloc(n*sizeof(int));
	for(i=1;i<=n;i++)
		fscanf(fp1,"%d",&a[i]);
	for(i=1;i<=n;i++){
		insert_bst(a[i]);
		printf("%d\t",a[i]);
		}
	do{
	printf("Enter:\n0 : to quit\n1 : to print the Binary Search Tree\n2 : to insert into the Binary Search Tree\n");
	scanf("%d",&input);	
	switch(input){
		case 0 : break;
		case 1 : print_bst(root); break;
		case 2 : printf("Enter the number : ");
				 scanf("%d",&value);
				 insert_bst(value);
				 break;
		default : printf("Error : Invalid Selection\n");
		}
	}while(input != 0);
	return 0;
}

void insert_bst(int value){
	struct bst *ptr, *par, *temp;
	temp = (struct bst *)malloc(sizeof(struct bst));
	temp->val = value;
	temp->left = NULL;
	temp->right = NULL;
	
	if(root == NULL)
		root = temp;
	else{
		ptr = root;
		while(ptr != NULL){
			par = ptr;
			if(value < ptr->val)
				ptr = ptr->left;
				
			else
				ptr = ptr->right;
			}
			if(value < par->val)
				par->left = temp;
				
			else
				par->right = temp;
		}	
	}

void print_bst(struct bst *x){
	if(x != NULL){
		print_bst(x->left);
		printf("%d\t",x->val);
		print_bst(x->right);
		}
	}
