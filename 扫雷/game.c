#include"game.h"

//�˵�2
void menu2()
{
	printf("**************************\n");
	printf("*******	1.ɨ    �� *******\n");
	printf("*******	2.��    �� *******\n");
	printf("*******	3.ȡ����� *******\n");
	printf("**************************\n");
}
//��ʼ��
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
//չʾ
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----��ɨ����Ϸ��----\n");
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
	printf("----��ɨ����Ϸ��----\n");

}
//�����׵�λ��
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;//1����9
		int y = rand() % col + 1;//1����9

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//��������
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

//��ȡ���ܵ�����
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

//��չ��Χ�����׵�����
void broad(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	//�ж������Ƿ�Խ��
	if (x == 0 || y == 0 || x == ROWS - 1 || y == COLS - 1)
		return;
	//�ж��Ƿ��Ѿ��Ų�
	if (show[x][y] != '*')
		return;
	int count = get_mine_count(mine, x, y);
	if (count > 0)
	{
		show[x][y] = count + '0';
		return;
	}
	//��չ
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

//���
int Flagmine(char show[ROWS][COLS], int row, int col,int flag_count)
{
	int x = 0;
	int y = 0;

	if (flag_count == EASY_COUNT)
	{
		printf("��ǵ�������ʵ��������ȣ��޷��ٱ��\n");
		return;
	}
	printf("��������Ҫ��ǵ�λ�ã�\n");
	scanf_s("%d %d", &x, &y);
	if (x > 0 && x <= row && y > 0 && y <= col)
	{
		//�жϸ�λ���Ƿ��ų�
		if (show[x][y] == '*')
		{
			show[x][y] = '!';
			flag_count++;
		}
		else
		{
			printf("��λ���Ѿ��ų����޷��ٱ��\n");
		}
	}
	else
	{
		printf("��������Ƿ�������������:\n");

	}
	return flag_count;

}

//ȡ�����
int CancelFlag(char show[ROWS][COLS], int row, int col, int flag_count)
{
	int x = 0;
	int y = 0;
	printf("��������Ҫȡ����ǵ�λ�ã�\n");
	scanf_s("%d %d", &x, &y);
	if (x > 0 && x <= row && y > 0 && y <= col)
	{
		//�жϸ�λ���Ƿ񱻱��
		if (show[x][y] == '!')
		{
			show[x][y] = '*';
			flag_count--;
		}
		else
		{
			printf("��λ��δ����ǹ����޷�ȡ����ǣ�\n");
		}
	}
	else
	{
		printf("��������Ƿ�������������:\n");

	}
	return flag_count;

}
//ɨ��
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int choice = 0;//ѡ��
	int flag_count = 0;//����׵ĸ���
	int win = 0;//�ж��Ƿ�Ӯ
	while (1)
	{
		menu2();
		scanf_s("%d", &choice);
		if (choice == 1)
		{
			int x = 0;
			int y = 0;
			printf("������Ҫ�Ų�����꣺\n");
			scanf_s("%d %d", &x, &y);
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				if (show[x][y] != '*')
				{
					printf("�������Ѿ����Ų���ˣ������ظ��Ų�!\n");
					system("pause");

				}
				else
				{
					//�������
					if (mine[x][y] == '1')
					{
						printf("���ź����㱻ը���ˣ�����\n");
						DisplayBoard(mine, ROW, COL);
						break;
					}
					else//���������
					{
						broad(mine, show, x, y);
						//ͳ��mine�����У�x��y�� ��Χ�м�����
						DisplayBoard(show, ROW, COL);
					}
				}
			}
			else
			{
				printf("��������Ƿ�������������\n");
			}
		}
		else if (choice == 2)
		{
			printf("�����ף�\n");
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
			printf("�����������������!\n");
		}
		win = TravelBoard(show, ROW, COL);
		if (win == EASY_COUNT)
		{
			break;
		}
	}

	if (win == EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ���\n");
		DisplayBoard(mine, ROW, COL);

	}

}

