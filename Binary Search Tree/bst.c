//Implement Inorder, Preorder and Postorder in Binary tree
#include<stdio.h>
#include<stdlib.h>

struct bst{
	int val;
	struct bst *left,*right;
};
struct bst* root;

struct stack{
  struct bst *t;
  struct stack *next;
};
struct stack *head = NULL;

void insert_bst(int value);
void inorder_traversal(struct bst *ptr);
void preorder_traversal(struct bst *ptr);
void postorder_traversal(struct bst *ptr);
void push(struct stack** top_ref,struct bst *t);
struct bst * pop(struct stack **top_ref);
int isEmpty(struct stack *top);

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
	//printf("\nPostorder Traversal: ");
	//postorder_traversal(root);
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
	struct bst * current = ptr;
	struct stack *s = NULL;
	int done = 0;
	while(!done){
		if(current!=NULL){
			push(&s, current);
			current = current->left;
			}
		else{
			if(!isEmpty(s)){
				current = pop(&s);
				printf("%d\t",current->val);
				current = current->right;
				}
			else
				done = 1;
			}
		}
	}
	
void preorder_traversal(struct bst *ptr){
	struct bst * current = ptr;
	struct stack *s = NULL;
	while(ptr!=NULL && current!=NULL){
		if(current!=NULL){
			printf("%d\t",current->val);
			}
		if(current->right!=NULL)
			push(&s, current->right);
		if(current->left!=NULL)
			current = current->left;
		else 
			current = pop(&s);
		}
	}
	
void postorder_traversal(struct bst *ptr){
	struct stack *s = NULL;
	struct bst * current = ptr;
	int done = 0;
	while(!done){
		if(current!=NULL){
			push(&s, current);
			current = current->left;
			}
		else{
			if(!isEmpty(s)){
				current = pop(&s);
				printf("%d\t",current->val);
				current = current->right;
				}
			else
				done = 1;
			}
		}  
	}

void push(struct stack** top_ref,struct bst *t){
    struct stack *new_bstnode = (struct stack *)malloc(sizeof(struct stack));
    if(new_bstnode == NULL){
		//printf("Stack Overflow\n");
		exit(0);
		}
		new_bstnode->t = t;
		new_bstnode->next = *top_ref;
		*top_ref = new_bstnode;
}

struct bst * pop(struct stack **top_ref){
	struct bst * res;
	struct stack *top;
	if(isEmpty(*top_ref)){
		//printf("Stack Underflow\n");
		return NULL;
		}
	else{
		top = *top_ref;
		res = top->t;
		*top_ref = top->next;
		free(top);
		return res;
		}
	}

int isEmpty(struct stack *top){
	return (top==NULL)?1:0;
	}
