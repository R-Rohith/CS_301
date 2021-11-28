#include<stdio.h>
#include<stdlib.h>
struct T_Node{ int val; struct T_Node *less,*more; };
struct T_Node *root=NULL,**node_arr;
int max,min,size;
int main()
{
	void Add_Tree();
	void Del_Tree();
	void Dis_Tree(struct T_Node*,int*);
	int opt,count;
menu:
	count=-1;
	printf("\n\nAVL Implementation Using Linked List\n");
	printf("\nAvailable Options:\n1. Add to Tree\n2. Delete from Tree\n3. Display Tree\n0. Exit\n");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1: Add_Tree();break;
		case 2: Del_Tree();break;
		case 3: Dis_Tree(root,&count);break;
		case 0: return 0;
		default: printf("Invalid Input\n");
	}
	goto menu;
}
void Add_Tree()
{
	void Bal_Tree();
	struct T_Node *node,*t1,*t2;
	t2=root;
	node=(struct T_Node*)malloc(sizeof(struct T_Node));
	if(node==NULL)
		printf("Ran out of memory!\nCannot add new node\n");
	else
	{
		printf("Enter the value: ");
		scanf("%d",&node->val);
		node->less=NULL;
		node->more=NULL;
		if(t2==NULL)
		{
			root=node;
			size++;
		}
		else
		{
			while(t2!=NULL)
			{
				t1=t2;
				if(node->val==t1->val)
					break;
				else if(node->val<t1->val)
					t2=t1->less;
				else
					t2=t1->more;
			}
			if(node->val<t1->val)
			{
				t1->less=node;
				size++;
				Bal_Tree();
			}
			else if(node->val>t1->val)
			{ 
				t1->more=node;
				size++;
				Bal_Tree();
			}
			else
			{
				printf("Value already exists...\n");
				free(node);
				return;
			}
		}
		printf("%d added to the tree\n",node->val);
	}
}
void Del_Tree()
{
	struct T_Node *node,*t1,*t2,*t3;
	int del_val;
	void Bal_Tree();
	printf("\nEnter the value to be deleted: ");
	scanf("%d",&del_val);
	if(root==NULL)
		printf("\nTree is empty, no element to delete\n");
	else
	{
		t2=root;
		while(t2!=NULL)
		{
			t1=t2;
			if(t1->val==del_val)
				break;
			else if(t1->val>del_val)
				t2=t1->less;
			else
				t2=t1->more;
			t3=t1;
		}
		if(t2!=NULL)
		{
			node=t1;
			if(node==root)
			{
				if(node->less==NULL)
					root=node->more;
				else
				{
					root=node->less;
					t2=node->less;
					while(t2->more!=NULL)
						t2=t2->more;
					t2->more=node->more;
				}

			}
			else
			{
				if(node->less==NULL)
				{
					if(t3->less==node)
						t3->less=node->more;
					else
						t3->more=node->more;
				}
				else
				{
					if(t3->less==node)
						t3->less=node->less;
					else
						t3->more=node->less;
					t1=node->less;
					while(t1->more!=NULL)
						t1=t1->more;
					t1->more=node->more;
						
				}
			}
			free(node);
			size--;
			Bal_Tree();
			printf("%d removed from tree\n",del_val);
		}
		else
			printf("\nElement is not present in the tree\n");
	}
}
void Dis_Tree(struct T_Node *node,int *count)
{
	void Dis_Tree(struct T_Node*,int*);
	if(node!=NULL)
	{
		*count+=1;
		Dis_Tree(node->more,count);
		for(int i=0;i<*count;i++)printf("\t");
		printf("%d\n",node->val);
		Dis_Tree(node->less,count);
		*count-=1;
	}
}
void Bal_Tree()
{
	struct T_Node *t1,*t2;
	int i=0,j=1;
	struct T_Node* trav(struct T_Node*,int,int,int,int*);
	max=0;
	min=0;
	trav(root,0,0,0,NULL);
	if((max-min)>1)
	{
		while(j<size)
			j=((j+1)*2)-1;
		node_arr=(struct T_Node**)malloc(j*sizeof(struct T_Node*));
		if(node_arr==NULL)
		{
			printf("Ran out of memory\nFailed to balance tree\n");
			return;
		}
		trav(root,1,0,0,&i);
		i--;
		for(int k=j-size,q=j-1;k>0;k--)
		{
			node_arr[q]=NULL;
			node_arr[q-1]=node_arr[i];
			q-=2;
			i-=1;
		}
		root=trav(NULL,2,0,j-1,NULL);
		free(node_arr);
	}

}
struct T_Node* trav(struct T_Node *node,int type,int c,int d,int *a_i)
{
	struct T_Node* trav(struct T_Node*,int,int,int,int*);
	if(type==0)
	{
		if(node!=NULL)
		{
			c++;
			trav(node->less,0,c,0,NULL);
			trav(node->more,0,c,0,NULL);
		}
		else 
		{
			if(max<c)
			max=c; 
			if((min>c)||(min==0))
			min=c;
		}
		return NULL;
	}
	else if(type==1)
	{
		if(node!=NULL)
		{
			trav(node->less,1,0,0,a_i);
			node_arr[*a_i]=node;
			*a_i+=1;
			trav(node->more,1,0,0,a_i);
		}
		return NULL;
	}
	else if(type==2)
	{
		type=c+(d-c)/2;
		node=node_arr[type];
		if(node!=NULL)
		{
			if(c==d)
			{
				node->less=NULL;
				node->more=NULL;
			}
			else
			{
				node->less=trav(NULL,2,c,type-1,NULL);
				node->more=trav(NULL,2,type+1,d,NULL);
			}
		}
		return node;
	}
}
