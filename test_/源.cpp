#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	const char* p = "zhangpengwei@bitedu.tech";
	const char* sep = ".@";
	char arr[30];
	char* str = NULL;
	strcpy(arr, p);//�����ݿ���һ�ݣ�����arr���������
	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
	{
		printf("%s\n", str);
	}
}