#include "SqStack.h"

int main()
{
	int flag = 0;
	SqStack *head = (SqStack*)malloc(sizeof(SqStack));
	head->elem = NULL;
	head->size = 0;
	head->top =-1;
	while(SUCCESS)
	{

    	system("cls");
    	printf(" ˳��ջ����\n--------------------------\n");
        printf(" 1.����˳��ջ               \n");
        printf(" 2.�ж�˳��ջ�Ƿ�Ϊ��       \n");
        printf(" 3.��ȡջ������             \n");
        printf(" 4.���˳��ջ               \n");
        printf(" 5.����˳��ջ               \n");
        printf(" 6.���ջ��                 \n");
        printf(" 7.������ջ                 \n");
        printf(" 8.���ݳ�ջ                 \n");
        printf(" 9.�˳�                     \n");
        printf("--------------------------  \n");
        printf("--------------------------  \n");
        printf("��ǰ����״̬:");
        if(flag)
        {

               printStack(head);
        }
        else
        {
                printf("ؿ���ӡ���(ʲô��û��)\n");
        }
	printf("--------------------------\n");
        printf("������ſ����ж�Ӧ����:");
	 switch(Input())
        {
                case 1:
			if(!flag)
			{
				printf("������Ҫ������ջ�Ĵ�С(����������");
				int k = Input();
				initStack(head,k);
				flag = 1;
				break;
			}
			else
			{
				printf("����˳��ջ�����ٵ�ǰջ������´���\n");
				break;
			}
               case 2:
                        if(flag)
                        {
                                isEmptyStack(head);
                        }
                        else
                        {
                                printf("û��ջ\n");
                        }
                        break;
                case 3:
			if(flag)
                        {
                        	int j=0;
				getTopStack(head,&j);

                        }
                        else
                        {
                                printf("û��ջ\n");
                        }
                        break;
                case 4:
                        if(flag)
                        {
				clearStack(head);
                        }
                        else
                        {
                               printf("û��ջ\n");
                        }
                        break;
                case 5:
                        if(flag)
                        {
                                destroyStack(head);
                                flag = 0;
                        }
                        else
                        {
                              printf("û��ջ\n");
                        }
                        break;
                case 6:
                        if(flag)
                        {
                        	int z=0;
                                stackLength(head,&z);
                        }
                        else
                        {
                               printf("û��ջ\n");
                        }
                        break;
                case 7:
                        if(flag)
                        {
                                int i;
                                printf("������Ҫ��ջ������:");
                                i=Input();
                                pushStack(head,i);
                        }
                        else
                        {
                               printf("û��ջ\n");
                        }
                        break;
                case 8:
                        if(flag)
                        {
                        	int x=0;
                                popStack(head,&x);
                        }
                        else
                        {
                                printf("û��ջ\n");
                        }
                        break;
                case 9:
                        exit(0);
                default:
                        printf("�޸����\n");
                        break;
        }
        system("pause");
    }
    return 0;
}
