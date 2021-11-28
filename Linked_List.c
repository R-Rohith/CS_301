#include<stdio.h>
#include<stdlib.h>
struct Node{			
	int num;
	struct Node *next;};
int main()
{
	void reverselist(struct Node*);
	struct Node *LL=NULL,*node=NULL;
	printf("Creating Linked List...\n");
	for(int i=0;i<10;i++)
	{
		if(i==0)
		{
			node=(struct Node*)malloc(sizeof(struct Node));
			LL=node;
		}
		else
		{
			node->next=(struct Node*)malloc(sizeof(struct Node));
			node=node->next;
		}
		node->num=i*2;
	}
	node->next=NULL;
	node=LL;
	printf("Printing the List...\n|");
	while(node!=NULL)
	{
		printf("%d->",node->num);
		node=node->next;
	}
	printf("\b\b| \n");
	reverselist(LL);
	printf("\nGOODBYE\n");
	return 0;
}
void reverselist(struct Node *LL)
{
	struct Node *node,*ll=NULL,*t;
	printf("\nReversing List...\n");
	t=LL;
	do
	{
		node=(struct Node*)malloc(sizeof(struct Node));
		node->num=t->num;
		node->next=ll;
		ll=node;
		t=t->next;	
	}while(t!=NULL);
	printf("Printing the List...\n|");
	while(node!=NULL)
	{
		printf("%d->",node->num);
		node=node->next;
	}
	printf("\b\b| \n");
}	