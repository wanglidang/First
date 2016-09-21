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
	static int i,j;
	if(is_full(s))
	{
		printf("seqlist is full.\n");
		return false;
	}
	s->last++;
	s->data[s->last] = n;                 //先将它放在最后面，然后往前比较大小，比直接插入中间要简单
	for(i=s->last; i>0; i--)
	{
		if(s->data[i-1] > s->data[i])
		{
			j=s->data[i-1];
			s->data[i-1]=s->data[i];
			s->data[i]=j;
		}
		break;
	}
	printf("now the list is : ");
	for(i=0;i<=s->last;i++)
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
	for(i=0;i <=s->last;i++)            //注意临界值
	{
		if(m == s->data[i])      
		{
			
			for(j=i+1;j<SIZE-1;j++,i++)
			{
				s->data[i]=s->data[j];	
				f++;
			}
			s->last -= 1;
			break;
		}		
	}
	printf("now the list is : ");
	for(i=0;i<=s->last;i++)
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
				printf("push error\n");
			}
		}
		else if(n<0)
		{
			m = -n;
			if(delete(m,s)==false)
			{
				printf("delete error\n");
			}	
		}
		else if(n==0)
		break;	
	}
	return 0;
}