/* Using list write a program to
	1. count the number of self loops in a graph
	2. compute the indegree and outdegree of the given graph
	3. find out the number of isolated nodes in a graph
 */
#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node *p;
};
struct node **head;

void create_node(int V, int i);
void insert_node(int i,int j);
void print_node(int i);
void self_loop(int V);
void outdegree(int V);
void indegree(int V);
void isolated_node(int V);

int main(void){
	int i,j,vertex,V;
	FILE *fp;
	fp = fopen("input.txt","r");
	fscanf(fp,"%d",&V);

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
	self_loop(V);
	outdegree(V);
	indegree(V);
	isolated_node(V);

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

void self_loop(int V){
	 int i,count=0;
	 struct node *temp = (struct node * )malloc(sizeof(struct node));
	 for(i=1;i<=V;i++){
		 temp = head[i]->p;
		 if(temp==NULL)
            break;
         while(temp->p != NULL){
			if(i == temp->val)
				count++;
			temp = temp->p;
			}
			if(i == temp->val)
				count++;
	 }
	 printf("Number of Self Loops in the Graph : %d\n\n",count);
 }

void outdegree(int V){
	 int i,count=0;
	 struct node *temp = (struct node * )malloc(sizeof(struct node));
	 for(i=1;i<=V;i++){
		 count = 0;
		 temp = head[i]->p;
		 if(temp==NULL){
			 printf("Outdegree of Vertex %d = 0\n",i);
			 break;
		 }
		 while(temp->p != NULL){
			count++;
			temp = temp->p;
		 }
		 printf("Outdegree of Vertex %d = %d\n",i,count+1);
	 }
	 printf("\n");
 }

void indegree(int V){
	int i,count[V];
	for(i=1;i<=V;i++)
		count[i] = 0;
	struct node *temp = (struct node * )malloc(sizeof(struct node));
	for(i=1;i<=V;i++){
		temp = head[i]->p;
		if(temp==NULL)
            break;
		while(temp->p != NULL){
			count[temp->val]++;
			temp = temp->p;
		}
		count[temp->val]++;
	}
	for(i=1;i<=V;i++)
		printf("Indegree of Vertex %d = %d\n",i,count[i]);
	printf("\n");
}

void isolated_node(int V){
	int i, indegree[V], outdegree[V], isolated=0;
	struct node *temp = (struct node * )malloc(sizeof(struct node));
	for(i=1;i<=V;i++){
		indegree[i] = 0;
		outdegree[i] = 0;
	}
	for(i=1;i<=V;i++){
		temp = head[i]->p;
		if(temp==NULL)
            break;
		while(temp->p != NULL){
			indegree[temp->val]++;
			temp = temp->p;
		}
		indegree[temp->val]++;
	}
	for(i=1;i<=V;i++){
		 temp = head[i]->p;
		 if(temp==NULL)
			 break;
		 while(temp->p != NULL){
			outdegree[i]++;
			temp = temp->p;
		 }
	 }
	for(i=1;i<=V;i++){
		if(indegree[i] == 0 && outdegree[i] == 0)
			isolated++;
	}
	printf("Number of Isolated nodes in the Graph : %d\n",isolated);
}
