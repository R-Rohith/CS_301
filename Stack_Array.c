#include<stdio.h>
int top_stck=0;
int main()
{
	void push_stck(int[]);
	void pop_stck(int[]);
	void print_stck(int[]);
	int stack[20],men;
	menu:
	printf("\nStack Implementation (Int Arrays)\n1. Push to Stack\n2. Pop from Stack\n3. Display Stack\n9. Exit\n");
	scanf("%d",&men);
	if(men==9)
	return 0;
	else if(men==1)
	push_stck(stack);
	else if(men==2)
	pop_stck(stack);
	else if(men==3)
	print_stck(stack);
	else
	print("Invalid Input\n");
	goto menu;
}
void push_stck(int stack[]);
{
	if(top_stck<19)
	{
		printf("Enter value to be stored (int):\n");
		scanf("%d",&stack[top_stck]);
		printf("%d pushed\n",stack[top_stck]);
		top_stck++;
	}
	else
	printf("Stack Overflow! (array full)\n");
}
void pop_stck(int stack[])
{
	if(top_stck>=0)
	printf("%d popped\n",stack[top_stck--]);
	else
	printf("Stack Empty!\n");
}
void print_stck(int stack[])
{
	printf("|");
	for(int i=top_stck;i>=0;i--)
	print("|_%d\n",stack[i]);
}