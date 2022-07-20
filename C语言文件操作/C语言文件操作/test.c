#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<errno.h>
#include<assert.h>
#pragma warning(disable : 4996)

//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		//printf("打开文件失败\n");
//		printf("%s\n", strerror(errno));
//		exit(-1);
//	}
//
//	//写文件
//
//
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

////写文件
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		exit(-1);
//	}
//
//	//写文件
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
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

////读文件
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		exit(-1);
//	}
//
//	//读文件
//	int ch = 0;
//	while ((ch = fgetc(pf)) != EOF)
//	{
//		printf("%c ", ch);
//	}
//	printf("\n");
//
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
////写一行
//int main()
//{
//	//打开文件
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
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


////读一行
//int main()
//{
//	//打开文件
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
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
//int main()
//{
//	//实现一个代码将data.txt 拷贝一份生成data2.txt
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
//	//拷贝文件
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
//	struct Stu s = { "张三", 20, 99.5 };
//	FILE* pf = fopen("data.txt", "w");
//	assert(pf);
//
//	//写格式化数据
//	fprintf(pf, "姓名：%s  年龄：%d  分数：%.2lf", s.name, s.age, s.d);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	struct Stu s = { "张三", 20, 99.5 };
//	FILE* pf = fopen("data.txt", "r");
//	assert(pf);
//	
//	//读格式化的数据
//	fscanf(pf, "%s %d %lf", s.name, &s.age, &s.d);
//	//printf("%s %d %lf\n", s.name, s.age, s.d);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	struct Stu s[2] = { {"张三", 20, 99.5},{"李四",21,98.5} };
//	FILE* pf = fopen("data.txt", "wb");
//	assert(pf);
//	
//	//按照二进制的方式写文件
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
//	//按照二进制的方式读文件
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
	struct Stu s = { "张三", 20, 99.5 };
	struct Stu temp = { 0 };

	char buff[100] = { 0 };
	sprintf(buff, "%s %d %lf", s.name, s.age, s.d);
	printf("%s\n", buff);

	sscanf(buff, "%s %d %lf", temp.name, &temp.age, &temp.d);
	printf("%s %d %lf\n", temp.name, temp.age, temp.d);
	return 0;
}
