#include<stdio.h>
#include<stdlib.h>

int Find(int *matrix, int rows, int cloumns, int number)
{
	if (NULL != matrix && rows > 0 && cloumns > 0)
	{
		int row = 0;
		int cloumn = cloumns - 1;

		while (row < rows && cloumn >= 0)
		{
			if (matrix[row*cloumns + cloumn] == number)
				return 1;
			else if (matrix[row*cloumns + cloumn] < number)
				row++;
			else
				cloumn--;
		}
	}
	return -1;
}

int main()
{
	int matrix[4][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	int ret = Find((int*)matrix, 4, 4, 15);
	printf("%d\n", ret);
	ret = Find((int*)matrix, 4, 4, 1);
	printf("%d\n", ret); 
	ret = Find((int*)matrix, 4, 4, 7);
	printf("%d\n", ret); 
	ret = Find((int*)matrix, 4, 4, 5);
	printf("%d\n", ret);
	system("pause");
	return 0;
}

