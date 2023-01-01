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
		menu();//打印菜单

		printf("请选择:>");
		scanf_s("%d", &input);
		
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束！\n");
			break;
		default:
			printf("输入错误，请重新选择。\n");
			break;
		}
	} while (input);
	
	return 0;
}
void game(void)
{
	//猜数字游戏的实现
	//  1.要生成随机的数字
	int ret = rand()%100+1;
	//printf("ret=%d\n", ret);
	//  2.要猜数字
	int num;
	printf("游戏开始！输出你要猜的数字:>");
	while (1)
	{
		scanf_s("%d", &num);

		if (num > ret)
		{
			printf("你猜大了！\n");
		}
		else if (num < ret)
		{
			printf("你猜小了！\n");
		}
		else
		{
			printf("恭喜你！猜对了！\n");
			break;
		}
	}

}