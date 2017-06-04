#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define BLACK 0
#define WHITE 1
#define GRAY 2

int  *color, *discoverytime,front,rear,length;

struct node{
	int val;
	struct node *p;
};
struct node **head;

void create_node(int V, int i);
void insert_node(int i,int j);
void print_node(int i);
void bfs(int V, struct node *source);
void enqueue(struct node *Q[], struct node *source);
int dequeue(struct node * Q[]);
void print_path(struct node *source, struct node * destination, struct node * parent[]);

int main(void){
	int i,j,vertex,V;
	FILE *fp;
	fp = fopen("input.txt","r");
	fscanf(fp,"%d",&V);
	color = (int *)malloc((V+1)*sizeof(int));
	discoverytime = (int *)malloc((V+1)*sizeof(int));
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
	bfs(V,head[1]->p);
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

void bfs(int V, struct node *source){
	struct node * parent[V], *Q[V*V], *temp,*n;
	int u,i;
	length = V*V;
	front = 1 ;
	rear = 1 ;
	for(u=0;u<V*V;u++)
		Q[u] = NULL;
    printf("line 88\n");
	for(u=1;u<=V;u++){
		if(source->val == u)
			continue;
		color[u] = WHITE;
		discoverytime[u] = INT_MAX;
		parent[u] = NULL;
		printf("color[%d] = %d, discoverytime[%d] = %d\n",u,color[u],u,discoverytime[u]);
	}
	printf("line 96, source->val = %d\n",source->val);
	color[source->val] = GRAY;
	discoverytime[source->val] = 0;
	parent[source->val] = NULL;
	enqueue(Q,source);
	printf("line 101\n");
	while(front!=rear){
		i = dequeue(Q);
		n = head[i]->p;
		if(n==NULL)
			continue;
        printf("line 107 temp->v = %d, n->val=%d\n",head[i]->p->val,n->val);
		while(n->p != NULL){
            printf("line 110\n");
			if(color[n->val] == WHITE){
			    printf("inside if\n");
				color[n->val] = GRAY;
				discoverytime[n->val] = discoverytime[head[i]->p->val]+1;
				parent[n->val] = head[i];
				printf("line 114 color[%d]: %d, discoverytime[%d]: %d, parent[%d] = %d\n",n->val,color[n->val],n->val,discoverytime[n->val],n->val,parent[n->val]);
				enqueue(Q,n);
			}
            n = n->p;
		}
		printf("line 118\n");
		if(color[n->val] == WHITE){
				color[n->val] = GRAY;
				discoverytime[n->val] = discoverytime[head[i]->p->val]+1;
				parent[n->val] = head[i];
				enqueue(Q,n);
			}
        printf("line 122\n");
		color[temp->val] = BLACK;

		printf("line 130 front = %d, rear = %d\n",front, rear);
		for(u=1;u<=V;u++)
                    printf("line 133 color[%d] : %d\n",u,color[u]);
		if(front!=rear){
            for(u=1;u<=V;u++){
                    printf("line 133 color[%d] : %d\n",u,color[u]);
                if(color[u]==WHITE){
                    printf("line 135\n");
                    color[u] = GRAY;
                    discoverytime[u] = 0;
                    parent[u] = NULL;
                    enqueue(Q,head[u]->p);
                    break;
                }
            }}

	}
	for(i=1;i<=V;i++)
        printf("%d : %d\n",i,discoverytime[i]);
	//print_path(head[1],head[6],parent);
}

void enqueue(struct node *Q[], struct node *source){
    Q[rear] = source;
	if(rear == length)
		rear = 1;
	else
		rear++;
}

int dequeue(struct node * Q[]){
   struct node * x = Q[front];
   if(front == length)
	   front = 1;
   else
	   front++;
   return x->val;
}

void print_path(struct node *source, struct node * destination, struct node* parent[]){
	if(source->val == destination->val)
		printf("->s\n");
	else if(parent[destination->val]==NULL)
		printf("No path from %d to %d \n",source->val, destination->val);
	else{
		print_path(source,parent[destination->val],parent );
		printf("%d",destination->val);
	}
}
