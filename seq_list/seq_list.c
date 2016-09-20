#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<stdbool.h>

#define SIZE 10

struct seq_list
{
	int data[SIZE];
	int last;
};

struct seq_list *init_list()
{
	struct seq_list *sl = malloc(sizeof(struct seq_list));
	
	if(sl != NULL)
	
		sl->last =-1;
		
	return sl;
}

bool is_full(struct seq_list *s)
{
	return s->last >= SIZE;
}

bool is_empty(struct seq_list *s)
{
		return s->last == -1;
}
bool push(int n,struct seq_list *s)
{
	static i,j;
	if(is_full(s))
	{
		printf("seqlist is full.\n");
		return false;
	}
	s->last++;
	if(s->last ==0)
	{
		s->data[s->last]=n;
	}
	else if(is_empty(s) ==false)
	{
		for(i=0;i<SIZE;i++)
		{
			if(n >= s->data[i])         //´ÓÐ¡Íù´óÅÅ
			{
				for(j=SIZE;j>i+2;j--)        
				{
					s->data[j]=s->data[j-1];
				}
				s->data[i+1] =n;
			}	
		}
	}
	printf("now the list is : ");
	for(i=0;i<s->last;i++)
	{
		printf("%d  ",s->data[i]);
	}
	printf("\n");

	return true;
}
bool delete(int m,struct seq_list *s)
{
	static int i,j,f=0;
	if(is_empty(s))
	{
		printf("seqlist is empty,please input number.\n");
		return false;
	}
	for(i=0;i <s->last;i++)
	{
		if(m == s->data[i])
		{
			s->last -= 1;
			for(j=i+1;j<s->last;j++,i++)
			{
				s->data[i]=s->data[j];	
				f++;
			}
			i =i-f;
		}		
	}
	printf("now the list is : ");
	for(i=0;i<s->last;i++)
	{
		printf("%d  ",s->data[i]);
	}
	printf("\n");
	
	return true;
}

int main(int argc,const char *argv[])
{
	struct seq_list *s =init_list();
	int n,m;
	while(1)
	{
		scanf("%d",&n);
		if(n>0)
		{
			if(push(n,s)==false)
			{
				perror("push");
				break;
			}
		}
		else if(n<0)
		{
			m = -n;
			if(delete(m,s)==false)
			{
				perror("delete");
			}	
		}
		else if(n==0)
		break;	
	}
	return 0;
}