#include"game.h"

//菜单2
void menu2()
{
	printf("**************************\n");
	printf("*******	1.扫    雷 *******\n");
	printf("*******	2.标    记 *******\n");
	printf("*******	3.取消标记 *******\n");
	printf("**************************\n");
}
//初始化
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] =set;
		}
	}
}
//展示
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----—扫雷游戏—----\n");
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----—扫雷游戏—----\n");

}
//设置雷的位置
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;//1——9
		int y = rand() % col + 1;//1——9

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//遍历雷盘
int TravelBoard(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int win = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '*' || show[i][j] == '!')
			{
				win++;
			}
		}
	}
	return win;
}

//获取四周的雷数
int get_mine_count(char board[ROWS][COLS], int x, int y)
{
	//return board[x - 1][y] +
	//	   board[x - 1][y - 1] +
	//	   board[x][y - 1] +
	//	   board[x + 1][y - 1] +
	//	   board[x + 1][y] +
	//	   board[x + 1][y + 1] + 
	//	   board[x][y + 1] + 
	//	   board[x - 1][y + 1] - 8 * '0';
	int count = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (board[x + i][y + j] == '1')
			{
				count++;
			}
		}
	}
	return count ;
}

//拓展周围不是雷的区域
void broad(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	//判断坐标是否越界
	if (x == 0 || y == 0 || x == ROWS - 1 || y == COLS - 1)
		return;
	//判断是否已经排查
	if (show[x][y] != '*')
		return;
	int count = get_mine_count(mine, x, y);
	if (count > 0)
	{
		show[x][y] = count + '0';
		return;
	}
	//拓展
	if (count == 0)
	{
		show[x][y] = '0';
		broad(mine, show, x - 1, y);
		broad(mine, show, x - 1, y - 1);
		broad(mine, show, x, y - 1);
		broad(mine, show, x + 1, y - 1);
		broad(mine, show, x + 1, y);
		broad(mine, show, x + 1, y + 1);
		broad(mine, show, x, y + 1);
		broad(mine, show, x - 1, y + 1);
	}
}

//标记
int Flagmine(char show[ROWS][COLS], int row, int col,int flag_count)
{
	int x = 0;
	int y = 0;

	if (flag_count == EASY_COUNT)
	{
		printf("标记的雷数与实际雷数相等，无法再标记\n");
		return;
	}
	printf("请输入你要标记的位置：\n");
	scanf_s("%d %d", &x, &y);
	if (x > 0 && x <= row && y > 0 && y <= col)
	{
		//判断该位置是否被排除
		if (show[x][y] == '*')
		{
			show[x][y] = '!';
			flag_count++;
		}
		else
		{
			printf("该位置已经排除，无法再标记\n");
		}
	}
	else
	{
		printf("输入坐标非法，请重新输入:\n");

	}
	return flag_count;

}

//取消标记
int CancelFlag(char show[ROWS][COLS], int row, int col, int flag_count)
{
	int x = 0;
	int y = 0;
	printf("请输入你要取消标记的位置：\n");
	scanf_s("%d %d", &x, &y);
	if (x > 0 && x <= row && y > 0 && y <= col)
	{
		//判断该位置是否被标记
		if (show[x][y] == '!')
		{
			show[x][y] = '*';
			flag_count--;
		}
		else
		{
			printf("该位置未被标记过，无法取消标记！\n");
		}
	}
	else
	{
		printf("输入坐标非法，请重新输入:\n");

	}
	return flag_count;

}
//扫雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int choice = 0;//选择
	int flag_count = 0;//标记雷的个数
	int win = 0;//判断是否赢
	while (1)
	{
		menu2();
		scanf_s("%d", &choice);
		if (choice == 1)
		{
			int x = 0;
			int y = 0;
			printf("请输入要排查的坐标：\n");
			scanf_s("%d %d", &x, &y);
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				if (show[x][y] != '*')
				{
					printf("改坐标已经被排查过了，不能重复排查!\n");
					system("pause");

				}
				else
				{
					//如果是雷
					if (mine[x][y] == '1')
					{
						printf("很遗憾，你被炸死了！！！\n");
						DisplayBoard(mine, ROW, COL);
						break;
					}
					else//如果不是雷
					{
						broad(mine, show, x, y);
						//统计mine数组中（x，y） 周围有几个雷
						DisplayBoard(show, ROW, COL);
					}
				}
			}
			else
			{
				printf("输入坐标非法，请重新输入\n");
			}
		}
		else if (choice == 2)
		{
			printf("请标记雷：\n");
			flag_count = Flagmine(show, ROW, COL,flag_count);
			DisplayBoard(show, ROW, COL);
		}
		else if (choice == 3)
		{
			flag_count = CancelFlag(show, ROW, COL, flag_count);
			DisplayBoard(show, ROW, COL);
		}
		else
		{
			printf("输入错误，请重新输入!\n");
		}
		win = TravelBoard(show, ROW, COL);
		if (win == EASY_COUNT)
		{
			break;
		}
	}

	if (win == EASY_COUNT)
	{
		printf("恭喜你，排雷成功！\n");
		DisplayBoard(mine, ROW, COL);

	}

}

