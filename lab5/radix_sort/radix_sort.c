/*
WAP TO IMPLEMENT RADIX SORT.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
	int val;
	struct node *p;
};

void insert_linked_list(int value);
void print_linked_list();
void greatest_number();
void radix_sort(int place);
struct node* head = NULL, *head0 = NULL, *head1=NULL, *head2=NULL, *head3=NULL,*head4=NULL, *head5=NULL, *head6=NULL, *head7=NULL, *head8=NULL, *head9=NULL;
int greatest_no;

int main(){
	int i,value,count=0;
	FILE *fp;

	fp = fopen("input.txt","r");
	while(!feof(fp)){
		fscanf(fp,"%d",&value);
		insert_linked_list(value);
	}
	greatest_number();
	printf("greatest_no = %d\n",greatest_no);

	while(greatest_no != 0){
        greatest_no /= 10;
        ++count;
    }
  
    for(i=1;i<=count;i++){
    	radix_sort(pow(10,i));
    }

	print_linked_list();
	return 0;
}

void insert_linked_list(int value){
	struct node *temp, *n;
	temp = (struct node *)malloc(sizeof(struct node));
	if(head == NULL){
	temp->val = value;
	temp->p = NULL;
	head = temp;
	}
	else{
		n = head;
		while(n->p != NULL)
			n = n->p;
		n->p = temp;
		temp->val = value;
		temp->p = NULL;
	}
}

void print_linked_list(){
	struct node *n;
	n = head;
	while(n->p != NULL){
		printf("%d\n",n->val);
		n = n->p;
	}
}

void greatest_number(){
	struct node *n;
	n = head;
	greatest_no = n->val;
	while(n->p != NULL){
		if(greatest_no < n->val){
			greatest_no = n->val;
			n = n->p;
		}
		else
			n = n->p;
	}
}

void radix_sort(int place){
	struct node *n,*m;
	n = head;
}
