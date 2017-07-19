/*************************************************************************
	> File Name: blank.c
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Tue 18 Jul 2017 10:45:58 PM CST
 ************************************************************************/

#include<stdio.h>

void ReplaceBlank(char string[], int length)
{
	if(string == NULL && length == 0)
		return;

	int strLength = length;
	int Blank = 0;
	int i = 0;
	while(string[i] != '\0')
	{
		if(string[i] == ' ')
			Blank++;
		i++;
	}
	printf("length = %d\n" , length);
	int newLength = 0;
	newLength = length + Blank * 2;
	printf("strLength = %d\n", strLength);

	while(strLength > 0 && newLength > strLength)
	{
		if(string[strLength] == ' ')
		{
			string[newLength--] = '$';
			string[newLength--] = '$';
			string[newLength--] = '$';
		}
		else
		{
			string[newLength--] = string[strLength];
		}
		strLength--;
	}
}

int main()
{
	char str[] = "talk is cheap show me the code";
	ReplaceBlank(str, sizeof(str));
	printf(" %s \n", str);
	return 0;
}
