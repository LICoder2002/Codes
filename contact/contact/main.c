#include"contact.h"

//ö��
enum Oprion
{
	EXIT, //�˳� 0
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW
};

//�˵�
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
	Contact con = { 0 };//����ͨѶ¼
	
	//��ʼ��ͨѶ¼
	InitContact(&con);

	do
	{
		menu();
		printf("��ѡ��");
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
			printf("�˳�ͨѶ¼��\n");
			system("pause");

			break;
		}
		default:
			printf("�����������������\n");
			break;
		}

	}while (input);

	return 0;

}