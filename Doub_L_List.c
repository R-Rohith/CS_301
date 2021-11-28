/*
Changes To The Program:
	The structure contained an extra variable to point to the previous node.
	The address of the first and last(head&tail) nodes needed to be saved.
	There were only few changes to the code that "generates" the Doubly Linked List: the pointer pointing to the prev. node has to be assigned every time a node is created.
	The reverselist() code had substantial change, it was very simple, as it is possible to traverse the doubly linked list in the reverse order.

Advantages: 
	Traversal is possible from tail to head.
	This makes rolling back to a previous node and reversing the list easier.
	More efficient in using memory than arrays.
And Disadvantages:	
	The whole list has to be traversed to reach the first node from the last node.
	Adding and deleting nodes is a bit complicated.
	Slower than arrays in accessing an element.
*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int num;
	struct Node *next,*prev;};
int main()
{
	void reverselist(struct Node*);
	struct Node *DLLH=NULL,*DLLT=NULL,*node=NULL;
	printf("Creating Doubly Linked List...\n");
	for(int i=0;i<10;i++)
	{
		if(i==0)
		{
			node=(struct Node*)malloc(sizeof(struct Node));
			DLLH=node;
			node->prev=NULL;
		}
		else
		{
			node->next=(struct Node*)malloc(sizeof(struct Node));
			node->next->prev=node;
			node=node->next;
		}
		node->num=i*2;
	}
	node->next=NULL;
	DLLT=node;
	node=DLLH;
	printf("Printing the List...\n|");
	while(node!=NULL)
	{
		printf("%d<->",node->num);
		node=node->next;
	}
	printf("\b\b\b|  \n");
	reverselist(DLLT);
	printf("\nGOODBYE\n");
	return 0;
}
void reverselist(struct Node *LL)
{
	struct Node *node,*Dll;
	printf("\nReversing List...\n");
	while(LL!=NULL)
	{
		if(LL->next==NULL)
		{
			node=(struct Node*)malloc(sizeof(struct Node));
			Dll=node;
			node->prev=NULL;
		}
		else
		{
			node->next=(struct Node*)malloc(sizeof(struct Node));
			node->next->prev=node;
			node=node->next;
		}
		node->num=LL->num;
		LL=LL->prev;
	}
	node->next=NULL;
	printf("Printing the List...\n|");
	node=Dll;
	while(node!=NULL)
	{
		printf("%d<->",node->num);
		node=node->next;
	}
	printf("\b\b\b|  \n");
}	