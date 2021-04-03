#include "LinkStack.h"





Status initLStack(LinkStack *s)//�����⿪�ٿռ�
{

	printf("������Ҫ������ջ�Ĵ�С(����������");
	s->count = Input();
	printf("������ջ�����ݡ�");
	for(int i=0;i<s->count;i++)
	{

		LinkStackPtr line=(LinkStackPtr)malloc(sizeof(StackNode));
		//�½ڵ���ͷ�ڵ㽨���߼���ϵ
		if(i == 0)
		{
			s->top = line;
			s->top->data = Input();
			s->top->next = NULL;
			printf("\n��������һ������:");
			continue;
		}
		line->next = s->top;
		line->data =Input();
		//����ͷָ���ָ��
		s->top=line;
		printf("\n��������һ������:");
	}
	printf("�����ɹ���\n");
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)
{
	if(s == NULL|| s->count==0)
	{
		printf("��δ����ջ\n");
		return ERROR;
	}
	else if(s->top==NULL)
	{
		printf("ջΪ�ա�\n");
		return SUCCESS;
	}
		printf("ջ�ǿա�\n");
		return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e)
{
	if(s == NULL|| s->count==0)
	{
		printf("��δ����ջ\n");
		return ERROR;
	}
	if(s->top == NULL)
	{
		printf("ջ�Կ�");
		return ERROR;
	}
	*e = s->top->data;
	printf("ջ������Ϊ%d",*e);
	return SUCCESS;
}
Status clearLStack(LinkStack *s)
{
	if(s->top == NULL|| s->count == 0)
	{
		printf("ջ�Ѿ��ǿյ��ˡ�\n");
		return ERROR;
	}
	LinkStackPtr temp;
	while(s->top!=NULL)
	{
		temp=s->top->next;
		s->top->data=0;
		s->top=temp;
	}
	printf("�����ϡ�\n");
	return SUCCESS;
}

Status destroyLStack(LinkStack *s)
{	LinkStackPtr temp;
	while(s->top!=NULL)
	{
		temp=s->top->next;
		free(s->top);
		s->top=temp;
	}
	s->count=0;
	printf("��ɡ�\n");
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length)
{
	if(s->top == NULL|| s->count==0)
	{
		printf("��û�д���ջ��\n");
		return ERROR;
	}
	*length = s->count;
	printf("ջ�ĳ���Ϊ%d",*length);
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)
{
	if(s->top == NULL|| s->count==0)
	{
		printf("��û�д���ջ��\n");
		return ERROR;
	}

	LinkStackPtr temp;
	temp=s->top;
	for(int i=0;i<s->count;i++)
	{

		s->top=s->top->next;
		if(i+1==s->count)
		{

			printf("ջ�Ѿ����ˡ�\n");
			return ERROR;
	 	}
	 	if(s->top==NULL)
		break;
	}
	s->top=temp;
	LinkStackPtr line=(LinkStackPtr)malloc(sizeof(StackNode));
	line->next = s->top;
	line->data =data;
	//����ͷָ���ָ��
	s->top=line;
	printf("��ջ�ɹ���\n");
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)
{
	if(s == NULL||s->count==0)
	{
		printf("��û�д���ջ��\n");
		return ERROR;
	}
	if(s->top == NULL)
	{
		printf("ջ�Կ�\n");
		return ERROR;
	}
	*data=s->top->data;
	LinkStackPtr temp;
	temp=s->top->next;
	free(s->top);
	//����ͷָ���ָ��
	s->top=temp;
	printf("����%d��ջ�ɹ���\n",*data);
	return SUCCESS;
}

/* printStack(LinkStack *s)
{


	LinkStackPtr temp;
	temp=s->top;
	for(int i=0;i<=s->count;i++)
	{
		printf("%d|",s->top->data);
		s->top=s->top->next;
	}
	s->top=temp;
	return ;
}*/

void printStack(LinkStack * s)
{
	StackNode * p = NULL;

	for (p = s->top; p; p = p->next)
	{
		printf("|%d", p->data);
	}
	printf("\n");
	return ;
}


int Input()
{
	int num = 0;
	int status = 0;
	char str[100];
	do
	{
		scanf("%s", str);
		status = SUCCESS;
		int i;
		for (i=0;str[i]!='\0';i++)
		{

			if (i == 0)
			{
				if (str[i]=='-'||str[i]=='+')
					continue;
			}
			else
			{
				if (str[i] < '0' || str[i] > '9')
				{
					status = ERROR;
				}
			}
		}
		if (status == ERROR)
		{
			printf("����������������:");
		}
		else
		{
			 i = 0;
			for (i = 0, num = 0; str[i] != '\0'; i++)
			{
				if (i == 0)
				{
					if (str[i] == '-' || str[i] == '+')
					{
						continue;
					}
					else
					{
						num *= 10;
						num += (str[i] - 48);
					}
				}
				else
				{
					num *= 10;
					num += (str[i] - 48);
				}
			}
			if (str[0] == '-')
			{
				num = -num;
			}
			// Check if the number entered is out of bounds.
			if (i>=10)
			{
				printf("������Χ������������:");
				status = ERROR;
			}
		}
	} while (status == ERROR);
	return num;
}
