#define _CRT_SECURE_NO_WARNINGS 1
/*--ʹ�ö��ַ������������в�������--*/
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
		printf("û�ҵ���");
	}
	else
	{
		 printf("�ҵ��ˣ��±�Ϊ%d\n", ret);
	}


	return 0;