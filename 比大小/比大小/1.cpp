#include<stdio.h>
int main()
{
	int a,b, c, max;
	printf("输出的值为 a,b,c:\n");
	scanf("%d,%d,%d", &a,&b, &c);
	max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	printf("最大值=%d\n", max);
}