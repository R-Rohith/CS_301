#include<stdio.h>
struct Node{ int val; struct Node *next;};
struct Node *head=NULL;
int main()
{
	void Push_Stack();
	void Pop_Stack();
	void Disp_Stack();
	int men;
	mentop:
	printf("\nStack Implementation ([int]Linked List)\n1. Push to Stack\n2. Pop from Stack\n3. Display Stack\n9. Exit\n");
	scanf("%d",&men);
	switch(men)
	{
		case 1: Push_Stack(); break;
		case 2: Pop_Stack(); break;
		case 3: Disp_Stack(); break;
		case 9: return 0;
		default: printf("Invalid input\n");
	}
	goto mentop;
}
void Push_Stack()
{
	struct Node *node;
	node=(struct Node*)malloc(sizeof(struct Node)); 
	node->next=head;
	head=node;
	printf("Enter the value");
	scanf("%d",&node->val);
}
void Pop_Stack()
{
	struct Node *node;
	node=head;
	head=head->next;
	free(node);
}
void Disp_Q()
{
	struct Node *node=head;
	printf("|");
	while(node!=NULL)
	{
		printf("|_%d\n",node->val);
		node=node->next;
	}
}