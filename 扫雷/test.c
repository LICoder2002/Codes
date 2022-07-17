#include"game.h"

//�˵�
void menu()
{
	printf("************************\n");
	printf("*******	1. play	********\n");
	printf("*******	0. exit	********\n");
	printf("************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS] = { 0 };//����Ų�����׵���Ϣ
	//��ʼ����������Ϊָ��������
	//mine ������û�в����׵�ʱ�򣬶���'0'
	InitBoard(mine, ROWS, COLS, '0');
	//show ������û���Ų��׵�ʱ��, ����'*'
	InitBoard(show, ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);

	//DisplayBoard(mine, ROW, COL);
	
	//������
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);

	//�Ų���
	FindMine(mine, show, ROW, COL);

}

int main()
{
	//����������������
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			//printf("ɨ��\n");
			system("cls");

			game();

			system("pause");
			system("cls");
			break;
		case 0:
			system("cls");

			printf("�˳���Ϸ\n");
			system("pause");
			break;
		default:
			printf("����������������룺\n");
			system("pause");
			system("cls");
			break;
		}
	} while (input);

	return 0;
}

