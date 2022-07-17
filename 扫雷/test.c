#include"game.h"

//菜单
void menu()
{
	printf("************************\n");
	printf("*******	1. play	********\n");
	printf("*******	0. exit	********\n");
	printf("************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//存放布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查出的雷的信息
	//初始化数组内容为指定的内容
	//mine 数组在没有布置雷的时候，都是'0'
	InitBoard(mine, ROWS, COLS, '0');
	//show 数组在没有排查雷的时候, 都是'*'
	InitBoard(show, ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);

	//DisplayBoard(mine, ROW, COL);
	
	//设置雷
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);

	//排查雷
	FindMine(mine, show, ROW, COL);

}

int main()
{
	//设置随机数生成起点
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			//printf("扫雷\n");
			system("cls");

			game();

			system("pause");
			system("cls");
			break;
		case 0:
			system("cls");

			printf("退出游戏\n");
			system("pause");
			break;
		default:
			printf("输入错误，请重新输入：\n");
			system("pause");
			system("cls");
			break;
		}
	} while (input);

	return 0;
}

