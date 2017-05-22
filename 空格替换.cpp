//空格替换

#include<stdio.h>
#include<stdlib.h>
void ReplaceBlank(char string[], int length)
{
	if (NULL == string || length <= 0)
	{
		return;
	}

	int stringlen = 0;
	int Blank = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == ' ')
			Blank++;
		i++;
	}
	//记录原始字符串长度
	stringlen = i;
	int NewLength = stringlen + Blank * 2;

	if (NewLength > length)
		return;

	while (stringlen >= 0 && NewLength > stringlen)
	{
		if (string[stringlen] == ' ')
		{
			string[NewLength--] = '%';
			string[NewLength--] = '0';
			string[NewLength--] = '2';
		}
		else
		{
			string[NewLength--] = string[stringlen];
		}
		stringlen--;
	}
}

int main()
{
	char arr[20] = "I am here.";
	ReplaceBlank(arr, 20);

	printf("%s\n", arr);
	system("pause");
	return 0;
}