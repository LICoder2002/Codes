#pragma warning(disable : 4996)
//д�ļ�

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	FILE* fp = fopen("myfile.txt", "w");
//	if (!fp) {
//		printf("fopen error!\n");
//	}
//	const char* msg = "hello world!\n";
//	int count = 5;
//	while (count--) {
//		fwrite(msg, strlen(msg), 1, fp);
//	}
//	fclose(fp);
//	return 0;
//}

#include <stdio.h>
#include <string.h>
int main()
{
	FILE* fp = fopen("myfile.txt", "r");
	if (!fp)
	{
		printf("fopen error!\n");
	}
	char buf[1024];
	const char* msg = "hello world!\n";
	while (1)
	{
		//ע�ⷵ��ֵ�Ͳ������˴��пӣ���ϸ�鿴man�ֲ���ڸú�����˵��
		size_t s = fread(buf, 1, strlen(msg), fp);
		if (s > 0) {
			buf[s] = 0;
			printf("%s", buf);
		}
		if (feof(fp)) {
			break;
		}
	}
	fclose(fp);
	return 0;
}