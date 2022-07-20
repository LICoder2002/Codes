#include"contact.h"

//枚举
enum Oprion
{
	EXIT, //退出 0
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW
};

//菜单
void menu()
{
	printf("***************************************\n");
	printf("********     1.add      2.del     *****\n");
	printf("********     3.search   4.modify  *****\n");
	printf("********     5.sort     6.show    *****\n");
	printf("********     0.exit               *****\n");
	printf("***************************************\n");
}

int main()
{
	int input = 0;
	Contact con = { 0 };//定义通讯录
	
	//初始化通讯录
	InitContact(&con);

	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DeleteContact(&con);
			break;
		case SEARCH:
			break;
		case MODIFY:
			break;
		case SORT:
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case EXIT:
		{
			SaveContact(&con);
			DestoryContact(&con);
			printf("退出通讯录！\n");
			system("pause");

			break;
		}
		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	}while (input);

	return 0;

}