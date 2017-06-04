/*my program was to get the names of student and marks of 3 subjects. I have created a bst and Inserted the values according to average of 
 * 3 subjects. To get 3 Students with top marks , I was going find maximum marks node and print it then deleting the node and 
 * repeating the process 3 times
 * */
#include<stdio.h>
#include<stdlib.h>

struct bst{
	int m1,m2,m3,mt;
	char name[10];
	struct bst *left,*right,*parent;
	};
struct bst *root=NULL;	

void insert_bst(char name[],int m1, int m2, int m3 ,int mt);
struct bst* maximum(struct bst *ptr);
struct bst* deleteNode(struct bst*,int key);
struct bst* minimum(struct bst *ptr);

int main(){
	int i,j,k=1,n,*m1,*m2,*m3,*mt;
	char *name;
	struct bst *node;
	FILE *fp;
	fp = fopen("input.txt","r");
	fscanf(fp,"%d",&n);
	m1 = (int *)malloc((n+1)*sizeof(int));
	m2 = (int *)malloc((n+1)*sizeof(int));
	m3 = (int *)malloc((n+1)*sizeof(int));
	mt = (int *)malloc((n+1)*sizeof(int));
	name = (char *)malloc((n*10)*sizeof(char));
	for(i=1;i<=n;i++,k++){
		for(j=0;j<10;j++)
			fscanf(fp,"%c ",&name[i*k+j]);
		fscanf(fp,"%d ",&m1[i]);
		fscanf(fp,"%d ",&m2[i]);
		fscanf(fp,"%d ",&m3[i]);
		mt[i] = (m1[i]+m2[i]+m3[i])/3;
		insert_bst(name,m1,m2,m3,mt);
		}
	/*for(i=1;i<=n;i++){
		printf("%s ",name[i]);
		printf("%d ",m1[i]);
		printf("%d ",m2[i]);
		printf("%d ",m3[i]);
		printf("%d ",mt[i]);
		printf("\n ");
		}*/
	node = maximum(root);
	printf("Top 1st student :%s",node->name);
	node = deleteNode(root,node->mt);
	node = maximum(root);
	printf("Top 2nd student%s",node->name);
	node = deleteNode(root,node->mt);
	node = maximum(root);
	printf("Top 3rd student :%s",node->name);	
	return 0;
	}

void insert_bst(char name[],int m1, int m2, int m3 ,int mt){
	struct bst *ptr, *par, *temp;
	temp = (struct bst *)malloc(sizeof(struct bst));
	temp->m1 = m1;
	temp->m2 = m2;
	temp->m3 = m3;
	temp->mt = mt;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;
	
	if(root == NULL)
		root = temp;
	else{
		ptr = root;
		while(ptr != NULL){
			par = ptr;
			if(mt < ptr->mt)
				ptr = ptr->left;
				
			else
				ptr = ptr->right;
			}
			if(mt < par->mt)
				par->left = temp;
			else
				par->right = temp;
			temp->parent = par;
		}	
	}

 struct bst* maximum(struct bst *ptr){
	 if(ptr!=NULL)
		return maximum(ptr->right);
	return ptr;
	 }
struct bst* minimum(struct bst *ptr){
	 if(ptr!=NULL)
		return maximum(ptr->left);
	return ptr;
	 }

struct bst* deleteNode(struct bst*,int key){
    if (root == NULL) return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minimum(root->right);
 
        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
