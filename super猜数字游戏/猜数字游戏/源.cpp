#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void game(void);
void menu(void)
{
	printf("*******************\n");
	printf("******1.play*******\n");
	printf("*******************\n");
	printf("******0.exit*******\n");
	printf("*******************\n");
}
int main(void)
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();//��ӡ�˵�

		printf("��ѡ��:>");
		scanf_s("%d", &input);
		
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ������\n");
			break;
		default:
			printf("�������������ѡ��\n");
			break;
		}
	} while (input);
	
	return 0;
}
void game(void)
{
	//��������Ϸ��ʵ��
	//  1.Ҫ�������������
	int ret = rand()%100+1;
	//printf("ret=%d\n", ret);
	//  2.Ҫ������
	int num;
	printf("��Ϸ��ʼ�������Ҫ�µ�����:>");
	while (1)
	{
		scanf_s("%d", &num);

		if (num > ret)
		{
			printf("��´��ˣ�\n");
		}
		else if (num < ret)
		{
			printf("���С�ˣ�\n");
		}
		else
		{
			printf("��ϲ�㣡�¶��ˣ�\n");
			break;
		}
	}

}