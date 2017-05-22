//合并两个有序数组
#include<stdio.h>
#include<stdlib.h>

int* MergeArray(int* arr1, int* arr2,int length1,int length2)
{
	if (NULL == arr1 || NULL == arr2 )
		return 0;

	int Len = length1 + length2 - 1;
	length1--;
	length2--;
	while (length1 >= 0 && length2 >= 0)
	{
		if (arr1[length1] < arr2[length2])
		{
			arr1[Len--] = arr2[length2--];
			//length2--;
		}
		else
		{
			arr1[Len--] = arr1[length1--];
		}
		
	}
	if (length1 >= 0)
	{
		while (length1>=0)
		{
			arr1[Len] = arr1[length1--];
			Len--;
		}
	}
	else if (length2 >= 0)
	{
		while (length2>=0)
		{
			arr1[Len] = arr2[length2--];
			Len--;
		}
	}
	return arr1;
}

void display(int arr[],int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int Arr1[20] = {3, 5, 7, 9, 11, 15 };
	int Arr2[7] = { 2, 4, 6, 8, 10, 13, 16 };

	MergeArray(&Arr1, &Arr2, 6, 7);
	display(Arr1, sizeof(Arr1) / sizeof(Arr1[0]));
	system("pause");
	return 0;
}