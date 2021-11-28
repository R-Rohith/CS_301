#include<stdio.h>
struct Node{ int val; struct Node *next;};
struct Node *head=NULL,*tail=NULL;
int main()
{
	void Add_Q();
	void Rem_Q();
	void Disp_Q();
	int men;
	mentop:
	printf("\nQueue Implementation ([int]Linked List)\n1. Add to Queue\n2. Remove from Queue\n3. Display Queue\n9. Exit\n");
	scanf("%d",&men);
	switch(men)
	{
		case 1: Add_Q(); break;
		case 2: Rem_Q(); break;
		case 3: Disp_Q(); break;
		case 9: return 0;
		default: printf("Invalid input\n");
	}
	goto mentop;
}
void Add_Q()
{
	struct Node *node;
	node=(struct Node*)malloc(struct Node);  
	if(head==NULL)
	tail=node;
	else
	head->next=node;
	head=node;
	node->next=NULL;
	printf("Enter the value");
	scanf("%d",&node->val);
}
void Rem_Q()
{
	struct Node *node;
	node=tail;
	tail=tail->next;
	free(node);
}
void Disp_Q()
{
	struct Node *node=tail;
	printf("|");
	while(node!=NULL)
	{
		printf("%d->",node->val);
		node=node->next;
	}
	printf("\b\b| ");
}