#include"game.h"

void menu()
{
	printf("*********************************\n");
	printf("**********   1��play   **********\n");
	printf("**********   0��exit   **********\n");
	printf("*********************************\n");
}
void game()
{
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	char ret = 0;//������Ϸ״̬
	//����
	while(1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = isWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = isWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ�ˣ�\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ�ˣ�\n");
	}
	else
	{
		printf("ƽ��\n");
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
		printf("�����룺");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			system("pause");
			system("cls");
			break;
		case 0:
			printf("�˳���Ϸ\n");
			system("pause");
			break;
		default:
			printf("�����������������\n");
			system("pause");
			system("cls");
		}
	}while (input);
	return 0;
}