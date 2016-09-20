#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct seq_stack
{
	int *stack;
	int size;
	int top;	
};

struct seq_stack *init_stack(int size)
{
	struct seq_stack *s= malloc(sizeof(struct seq_stack));
	if(s !=NULL)
	{
		s->stack =calloc(size,sizeof(int));  //分配size个int大小的连续存储空间
		s->size = size;
		s->top =-1;
	}
	return s;
}

bool is_full(struct seq_stack *s)
{
	return s->top >=s->size-1;  //做判断是否为满
}

bool is_empty(struct seq_stack *s)
{
	return s->top == -1;
}

bool push(int data,struct seq_stack *s)
{
	if(is_full(s))
		return false;
	s->top++;
	s->stack[s->top] = data;
	
	return true;
}

bool pop(int *pm,struct seq_stack *s)
{
	if(is_empty(s))
		return false;
	*pm =s->stack[s->top];
	s->top--;
	
	return true;
}

int main(int argc,const char *argv[])
{
	struct seq_stack *s = init_stack(10);
	int n;
	
	scanf("%d",&n);
	while( n > 0 )
	{
		if((push(n%8,s)) == false)
		{
			printf("push() false.\n");
			exit(1);
		}
		printf("%d\n",n%8);
		n /=8;			
	}
	
	printf("0");
	int m;
	while(1)
	{
		if(pop(&m,s)==false)
		{
			break;
		}
		printf("%d",m);		
	}
	printf("\n");
	
	return 0;
}