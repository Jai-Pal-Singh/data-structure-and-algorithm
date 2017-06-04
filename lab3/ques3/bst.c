//Implement Inorder, Preorder and Postorder in Binary tree
#include<stdio.h>
#include<stdlib.h>

struct bst{
	int val;
	struct bst *left,*right;
};
struct bst* root;

void insert_bst(int value);
void inorder_traversal(struct bst *ptr);
void preorder_traversal(struct bst *ptr);
void postorder_traversal(struct bst *ptr);

int main(){
	int i,n,*a;
	FILE *fp;
	fp = fopen("input.txt","r");
	fscanf(fp,"%d",&n);
	a = (int*)malloc((n+1)*sizeof(int));
	for(i=1;i<=n;i++)
		fscanf(fp,"%d",&a[i]);
	printf("Given Sequence : ")	;
	for(i=1;i<=n;i++){
		insert_bst(a[i]);
		printf("%d\t",a[i]);
		}
	printf("\nInorder Traversal: ");
	inorder_traversal(root);
	printf("\nPreorder Traversal: ");
	preorder_traversal(root);
	printf("\nPostorder Traversal: ");
	postorder_traversal(root);
	printf("\n");
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
	
void inorder_traversal(struct bst *ptr){
	if(ptr!=NULL){
		inorder_traversal(ptr->left);
		printf("%d\t",ptr->val);
		inorder_traversal(ptr->right);
		}
	}

void preorder_traversal(struct bst *ptr){
	if(ptr!=NULL){
		printf("%d\t",ptr->val);
		preorder_traversal(ptr->left);
		preorder_traversal(ptr->right);
		}
	}
void postorder_traversal(struct bst *ptr){
	if(ptr!=NULL){
		postorder_traversal(ptr->left);
		postorder_traversal(ptr->right);
		printf("%d\t",ptr->val);
		}
	}
