/*
Changes:
	In Circularly Linked List the only change is that the last node points to the first node.
	Hence while traversing the loop condition should check for equality with the first node address instead on 'NULL'.
	Rest of the code is very similar to the linear linked list code.
Advantages:
	It is easier and faster to travel from the last node to the first node.
	Inserting and deleting nodes are simpler.
	More efficient in using memory than arrays.
Disadvantages:
	Reversing the list is very complicated.
	Rolling back to the previous node is not possible.
	Still slower than arrays in accessing an element.
	
*/
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
	node->next=LL;
	node=LL;
	printf("Printing the List...\n->");
	do
	{
		printf("%d->",node->num);
		node=node->next;
	}while(node!=LL);
	printf("\b\b-> \n");
	reverselist(LL);
	printf("\nGOODBYE\n");
	return 0;
}
void reverselist(struct Node *LL)
{
	struct Node *node,*tmp,*t,*ll;
	printf("\nReversing List...\n");
	t=LL;
	do
	{
		node=(struct Node*)malloc(sizeof(struct Node));
		if(t==LL)ll=node;
		node->num=t->num;
		node->next=tmp;
		tmp=node;
		t=t->next;	
	}while(t!=LL);
	ll->next=tmp;
	ll=tmp;
	node=ll;
	printf("Printing the List...\n->");
	do
	{
		printf("%d->",node->num);
		node=node->next;
	}while(node!=ll);
	printf("\b\b-> \n");
}	