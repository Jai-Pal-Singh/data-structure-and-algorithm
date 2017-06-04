#include<stdio.h>
#include<stdlib.h>

#define BLACK 0
#define WHITE 1
#define GRAY 2
 
int  *color, *discoverytime, *finishtime, time = 0;

struct node{
	int val;
	struct node *p;
};
struct node **head;

void create_node(int V, int i);
void insert_node(int i,int j);
void print_node(int i);
void dfs(int V);
void dfs_visit(struct node *parent[],int u);

int main(void){
	int i,j,vertex,V;
	FILE *fp;
	fp = fopen("input.txt","r");
	fscanf(fp,"%d",&V);
	color = (int *)malloc((V+1)*sizeof(int));
	discoverytime = (int *)malloc((V+1)*sizeof(int));
	finishtime = (int *)malloc((V+1)*sizeof(int));
	head = (struct node **)malloc((V+1)*sizeof(struct node *));
	for(i=1;i<=V;i++)
		create_node(V,i);

	for(i=1;i<=V;i++)
		for(j=1;j<=V;j++){
			fscanf(fp,"%d",&vertex);
			if(vertex == 1)
				insert_node(i,j);
		}

	for(i=1;i<=V;i++)
		print_node(i);

	printf("\n");
	
	dfs(V);
	for(i=1;i<=V;i++){
		printf("%d :\t%d\t%d\n",i,discoverytime[i],finishtime[i]);
	}
	
	fclose(fp);
	return 0;
	}

void create_node(int V, int i){
	head[i] = (struct node *)malloc(sizeof(struct node));
	head[i]->p = NULL;
}

void insert_node(int i,int j){
	struct node *temp = (struct node * )malloc(sizeof(struct node));
	struct node *n;
	temp->val = j;
	temp->p = NULL;
	n = head[i];
	while(n->p!=NULL)
		n = n->p;
	n->p = temp;
}
 void print_node(int i){
	 struct node *temp;
	 printf("%d",i);
	 temp = head[i]->p;
	 if(temp==NULL)
        return;
	 while(temp->p != NULL){
		 printf("->%d",temp->val);
		 temp = temp->p;
	 }
	 printf("->%d\n",temp->val);
 }
 
void dfs(int V){
	struct node * parent[V];
	int u;
	for(u=1;u<=V;u++){
		color[u] = WHITE;
		parent[u] = NULL;
	}
	for(u=1;u<=V;u++)
		if(color[u] == WHITE)
			dfs_visit(parent,u);
}

void dfs_visit(struct node * parent[], int u){
	struct node *temp;
	color[u] = GRAY;
	time++;
	discoverytime[u] = time;
	temp = head[u]->p;
	if(temp==NULL)
       return;
	while(temp->p != NULL){
		if(color[temp->val]==WHITE){
			parent[temp->val] = head[u];
			dfs_visit(parent,temp->val);
		}
		temp = temp->p;
	}
	if(color[temp->val]==WHITE){
			parent[temp->val] = head[u];
			dfs_visit(parent,temp->val);
		}
	color[u] = BLACK;
	time++;
	finishtime[u] = time;
}