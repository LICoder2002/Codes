#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<errno.h>
#include<assert.h>
#pragma warning(disable : 4996)

//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		//printf("���ļ�ʧ��\n");
//		printf("%s\n", strerror(errno));
//		exit(-1);
//	}
//
//	//д�ļ�
//
//
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

////д�ļ�
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		exit(-1);
//	}
//
//	//д�ļ�
//	//fputc('a', pf);
//	//fputc('b', pf);
//	//fputc('c', pf);
//	//fputc('d', pf);
//	for (char ch = 'a'; ch <= 'z'; ch++)
//	{
//		//fputc(ch, pf);
//		fputc(ch, stdout);
//	}
//
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

////���ļ�
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		exit(-1);
//	}
//
//	//���ļ�
//	int ch = 0;
//	while ((ch = fgetc(pf)) != EOF)
//	{
//		printf("%c ", ch);
//	}
//	printf("\n");
//
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
////дһ��
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		exit(-1);
//	}
//
//	//fputs("hello world\n", pf);
//	//fputs("hehe\n", pf);
//
//
//	fputs("hello world\n", stdout);
//	fputs("hehe\n", stdout);
//
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


////��һ��
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		exit(-1);
//	}
//
//
//	char buff[1000] = {0};
//	fgets(buff, 3, pf);
//	printf("%s\n", buff);
//
//	fgets(buff, 3, pf);
//	printf("%s\n", buff);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
//int main()
//{
//	//ʵ��һ�����뽫data.txt ����һ������data2.txt
//	FILE* pr = fopen("data.txt", "r");
//	if (pr == NULL)
//	{
//		printf("open for reading: %s\n", strerror(errno));
//		exit(-1);
//	}
//
//	FILE* pw = fopen("data2.txt", "w");
//	if (pw == NULL)
//	{
//		printf("open for writing: %s\n", strerror(errno));
//		fclose(pr);
//		pr == NULL;
//		exit(-1);
//	}
//
//	//�����ļ�
//	int ch = 0;
//	while ((ch = fgetc(pr)) != EOF)
//	{
//		fputc(ch, pw);
//	}
//
//	fclose(pr);
//	pr = NULL;
//	fclose(pw);
//	pw = NULL;
//	return 0;
//}

struct Stu
{
	char name[20];
	int age;
	double d;
};

//int main()
//{
//	struct Stu s = { "����", 20, 99.5 };
//	FILE* pf = fopen("data.txt", "w");
//	assert(pf);
//
//	//д��ʽ������
//	fprintf(pf, "������%s  ���䣺%d  ������%.2lf", s.name, s.age, s.d);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

int main()
{
	struct Stu s = { "����", 20, 99.5 };
	FILE* pf = fopen("data.txt", "r");
	assert(pf);
	
	//����ʽ��������
	fscanf(pf, "%s %d %lf", s.name, &s.age, &s.d);
	//printf("%s %d %lf\n", s.name, s.age, s.d);

	fclose(pf);
	pf = NULL;
	return 0;
}