#include "SqStack.h"

Status initStack(SqStack *s,int sizes)//��ʼ��ջ
{
	s->elem=(ElemType *)malloc(sizeof(ElemType));
	if(s->elem==NULL)
	{
		printf("�ڴ治��,����ʧ�ܡ�");
		return ERROR;
	}
	if(sizes<=0)
	{
		printf("ջ��СҪ�����㡣");
		return ERROR;
	}
	s->size=sizes;
	s->top=-1;
	printf("������ջ�����ݡ�");
	for(int i=0;i<sizes;i++)
	{
		s->elem[i]=Input();
		if(i==sizes-1)
		{
			printf("������\n");//�Ӹ��Ƿ���չջ�ռ䣿
			s->top = i;
			break;
		}
		printf("��������һ������:");
	}

	printf("�ɹ�����\n");
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)
{
	if(s == NULL|| s->top==-1)
	{
		printf("ջΪ�ա�\n");
		return SUCCESS;
	}
		printf("ջ�ǿա�\n");
		return ERROR;
}

Status getTopStack(SqStack *s,ElemType *e)
{
	if(s == NULL|| s->size==0)
	{
		printf("��δ����ջ\n");
		return ERROR;
	}
	if(s->top == -1)
	{
		printf("ջ�Կ�");
		return ERROR;
	}
	*e = s->elem[s->top];
	printf("ջ������Ϊ%d",*e);
	return SUCCESS;
}

Status clearStack(SqStack *s)
{
	if(s == NULL|| s->top==-1)
	{
		printf("ջ�Ѿ��ǿյ��ˡ�\n");
		return ERROR;
	}
	s->top =-1;
	printf("�����ϡ�\n");
	return SUCCESS;
}

Status destroyStack(SqStack *s)
{
	if(s == NULL|| s->size==0)
	{
		printf("��û�д���ջ��\n");
		return ERROR;
	}
		s->size=0;
		free(s->elem);
		s->elem = NULL;
		printf("��ɡ�\n");
		return SUCCESS;
}


Status stackLength(SqStack *s,int *length)
{
	if(s == NULL|| s->top==-1)
	{
		printf("��û�д���ջ��\n");
		return ERROR;
	}
	* length =s->size;
	printf("ջ�ĳ���Ϊ%d",*length);
	return SUCCESS;
}


Status pushStack(SqStack *s,ElemType data)
{
	if(s == NULL|| s->size==0)
	{
		printf("��û�д���ջ��\n");
		return ERROR;
	}
	if(s->top == s->size-1)
	{
		printf("ջ�Ѿ����ˡ�\n");
		return ERROR;
	}

	s->elem[++s->top]=data;
	printf("��ջ�ɹ���\n");
	return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data)
{
	if(s == NULL|| s->size==0)
	{
		printf("��û�д���ջ.\n");
		return ERROR;
	}
	if(s->top == -1)
	{
		printf("ջ�Ѿ����ˡ�\n");
		return ERROR;
	}
	*data = s->elem[s->top--];
	printf("����%d�ѳ�ջ",*data);
	return SUCCESS;
}


void printStack(SqStack *s)
{
	for(int i=0;i<=s->top;i++)
	{
		printf("%d|",s->elem[i]);
	}
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
			printf("��������������:");
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

