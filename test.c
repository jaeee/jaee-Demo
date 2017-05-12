#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
void print(char* str)
{

}
//strcat
char* my_strcat(char* dest,  char* src)
{
	//判空
	assert(dest);
	assert(src);
	char* ret = dest;
	while (*dest != '\0')
		++dest;

	while (*dest++ = *src++)
		;
	*dest = '\0';
	return ret;
}

//strcmp(按照ASCII码值比较)
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 != NULL && str2 != NULL);
	int ret = 0;

	while ((ret = *str1 - *str2) && str1++&&str2++)
		;

	if (ret < 0)
		return -1;
	else
		return 1;
}
//strncat
char* my_strncat(char* dest, const char* src, int number)
{
	assert(dest != NULL&& src != NULL);
	char* ret = dest;
	while (*++dest != '\0')
		;

	while (number-- && (*dest++ = *src++))
		;
	*dest = '\0';
	return ret;
	
}
//strncmp
//strncpy
//strcpy
char* my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL&& src != NULL);
	char* ret = dest;

	while (*dest++ = *src++)
		;
	*dest = '\0';

	return ret;

}
//strlen
int my_strlen(const char* str)
{
	if (*str == '\0')
		return 0;
	return 1 + my_strlen(++str);
}
//memcpy
//

int main()
{
	char str1[20] = "hello ";
	char* str2 = "world";
	//printf("%s", my_strcat(str1,str2));
	//printf("%s", my_strncat(str1, str2, 5));
	//printf("%d", my_strlen(str1));
	//printf("%d", my_strcmp(str1,str2));
	printf("%s", my_strcpy(str1, str2));

	system("pause");
	return 0;
}