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

//int main()
//{
//	struct Stu s = { "����", 20, 99.5 };
//	FILE* pf = fopen("data.txt", "r");
//	assert(pf);
//	
//	//����ʽ��������
//	fscanf(pf, "%s %d %lf", s.name, &s.age, &s.d);
//	//printf("%s %d %lf\n", s.name, s.age, s.d);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	struct Stu s[2] = { {"����", 20, 99.5},{"����",21,98.5} };
//	FILE* pf = fopen("data.txt", "wb");
//	assert(pf);
//	
//	//���ն����Ƶķ�ʽд�ļ�
//	fwrite(&s, sizeof(struct Stu), 2, pf);
//
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
//int main()
//{
//	struct Stu s[2] = {0};
//	FILE* pf = fopen("data.txt", "rb");
//	assert(pf);
//
//	//���ն����Ƶķ�ʽ���ļ�
//	fread(s, sizeof(struct Stu), 2, pf);
//	printf("%s %d %lf\n", s[0].name, s[0].age, s[0].d);
//	printf("%s %d %lf\n", s[1].name, s[1].age, s[1].d);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


int main()
{
	struct Stu s = { "����", 20, 99.5 };
	struct Stu temp = { 0 };

	char buff[100] = { 0 };
	sprintf(buff, "%s %d %lf", s.name, s.age, s.d);
	printf("%s\n", buff);

	sscanf(buff, "%s %d %lf", temp.name, &temp.age, &temp.d);
	printf("%s %d %lf\n", temp.name, temp.age, temp.d);
	return 0;
}
