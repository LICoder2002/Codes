#include"game.h"

void menu()
{
	printf("*********************************\n");
	printf("**********   1、play   **********\n");
	printf("**********   0、exit   **********\n");
	printf("*********************************\n");
}
void game()
{
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	char ret = 0;//接收游戏状态
	//下棋
	while(1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = isWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = isWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢了！\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了！\n");
	}
	else
	{
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);

}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do 
	{
		menu();
		printf("请输入：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			system("pause");
			system("cls");
			break;
		case 0:
			printf("退出游戏\n");
			system("pause");
			break;
		default:
			printf("输入错误，请重新输入\n");
			system("pause");
			system("cls");
		}
	}while (input);
	return 0;
}