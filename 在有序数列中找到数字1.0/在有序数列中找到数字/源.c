#define _CRT_SECURE_NO_WARNINGS 1
/*--使用二分法在有序数列中查找数字--*/
#include<stdio.h>

int er_find(int* arr, int key, int length)
{
	int left = 0;
	int right = length-1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main(void)
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10, };
	int key = 10;
	int length = sizeof(arr) / sizeof(arr[0]);

	int ret = er_find( arr,  key,  length);
	if (ret == -1)
	{
		printf("没找到。");
	}
	else
	{
		 printf("找到了，下标为%d\n", ret);
	}


	return 0;