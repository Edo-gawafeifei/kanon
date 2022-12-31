////#include<stdio.h>
////int main()
////{
////	const int a = 60, b = 80;
////	int grade = 0;
////	printf("请输入你的成绩");
////	scanf("%d", &grade); 
////	printf("你的成绩为：%d\n",grade);
////	if (a > grade){
////		printf("你的成绩为不及格哟！不要灰心！加油!\n");
////	}
////	/*if (a <= grade < b){
////		printf("你的成绩为良，加油!!!\n");
////	}*/
////	if (grade >= b){
////		printf("你的成绩为优秀！你很棒！继续保持！\n");
////	}
////	
////}
//#include<stdio.h>
//int main()
//{
//	int a, b,max;
//	printf("请输入两位数字：");
//	scanf("%d,%d", &a, &b);
//	//if (a > b){
//	//	max = a;
//	//}
//	//else{
//	//	max = b;//可以避免a=b的情况
//	//}
//	max = b;
//	if (a > b){
//		max = a;
//	}
//	printf("最大值为%d。\n", max);
//
//}
#include<stdio.h>
int main()
{
	int a, b, c,max;
	printf("请输入三个数字：");
	scanf("%d,%d,%d", &a, &b, &c);
	max = a;//4 5 6
	if (a < b)
		max = b;
	if (a < c)
		max = c;
	printf("最大值为%d。\n", max);

}