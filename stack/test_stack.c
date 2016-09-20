#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
	int data;
	struct node *next;
};

struct stack
{
	struct node *top;
	int size;
};

struct stack *init_stack(void)
{
	struct stack *s = malloc(sizeof(struct stack));
	if(s != NULL)
	{
		s->top =NULL;
		s->size =0;
	}
	return s;
}

bool is_empty(struct stack *s)
{
	return s->size ==0;
}

void push(int data, struct stack *s)
{
	struct node *new = malloc(sizeof(struct node));
	if(new !=NULL)
	{
		new->data =data;
	}
	new->next = s->top;    //与下面的pop里面的s->top->next相对应
    s->top = new;
	s->size++;
}
bool pop(struct stack *s,int *pm)
{
	if(is_empty(s))
	return false;

	*pm = s->top->data;
	
	struct node *tmp =s->top;   
	s->top = s->top->next;   //与上面的push存起来的new->next相对应

	free(tmp);
	s->size--;
	return true;
}

int main(int argc, const char *argv[])
{
	struct stack *s =init_stack();

	int n;
	scanf("%d",&n);
	
	while(n>0)
	{
		push(n%8,s);
		printf("%d\n",n%8);
		n /=8;
	}

	int m;
	printf("0");
	while(1)
	{
		if(is_empty(s))
			break;
		pop(s,&m);
		
		printf("%d",m);
	}
	printf("\n");

	return 0;
}
