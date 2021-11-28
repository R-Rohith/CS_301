#include<stdio.h>
int head_q=0,tail_q=0;
int main()
{
	void add_q(int[]);
	void rm_q(int[]);
	void print_q(int[]);
	int queue[20],men;
	menu:
	printf("\nQueue Implementation (Int Arrays)\n1. Add to Queue\n2. Remove from Queue\n3. Display Queue\n9. Exit\n");
	scanf("%d",&men);
	if(men==9)
	return 0;
	else if(men==1)
	add_q(queue);
	else if(men==2)
	rm_q(queue);
	else if(men==3)
	print_q(queue);
	else
	print("Invalid Input\n");
	goto menu;
}
void add_q(int q[]);
{
	if((head_q-tail_q)<19)
	{
		if(head_q>=19)
		{
			for(int i=0;i<=(head_q-tail_q);i++)
			q[i]=q[i+tail_q];
			head_q=i-1;
			tail_q=0;
		}
		printf("Enter value to be stored (int):\n");
		scanf("%d",&q[head_q]);
		printf("%d added\n",q[head_q]);
		head_q++;
	}
	else
	printf("Queue full! (array full)\n");
}
void rm_q(int q[])
{
	if(tail_q<=head_q)
	printf("%d removed\n",q[tail_q++]);
	else
	printf("Queue Empty!\n");
}
void print_q(int q[])
{
	printf("|");
	for(int i=tail_q;i<=head_q;i++)
	print("%d->",q[i]);
	printf("\b\b| ");
}