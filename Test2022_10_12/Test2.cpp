//ţ��������MP3���λ�� https://www.nowcoder.com/questionTerminal/eaf5b886bd6645dd9cfb5406f3753e15?toCommentId=14643937

#include<iostream>
#include<string>
using namespace std;

void less_4(int n, string& str)
{
	int cur = 1; //��ʼλ��
	for (auto ch : str)
	{
		if (ch == 'U')
		{
			if (cur == 1)
				cur = n;
			else
				cur--;
		}
		else if (ch == 'D')
		{
			if (cur == n)
				cur = 1;
			else
				cur++;
		}
		else
			return;
	}

	for (int i = 1; i <= n; ++i)
		cout << i << " ";
	cout << endl << cur << endl;
}

void more_4(int n, string& str)
{
	int cur = 1;//��ʼλ��
	int pagestart = 1;//ҳ��

	for (auto ch : str)
	{
		if (ch == 'U')
		{
			if (cur == 1 && pagestart == 1)//��һ�ף�ҳ��
			{
				cur = n;
				pagestart = n - 3;
			}
			else if (cur == pagestart)//�ǵ�һ����Ϊҳ��
			{
				cur--;
				pagestart--;
			}
			else
			{
				cur--;
			}
		}
		else if (ch == 'D')
		{
			if (cur == n && pagestart == n - 3)
			{
				cur = 1;
				pagestart = 1;
			}
			else if (cur == pagestart + 3)
			{
				cur++;
				pagestart++;
			}
			else
			{
				cur++;
			}
		}
		else
		{
			return;
		}
	}

	for (int i = pagestart; i <= pagestart + 3; ++i)
	{
		cout << i << " ";
	}
	cout << endl << cur << endl;
}

int main()
{
	int n = 0; 
	string str;

	while (cin >> n >> str)
	{
		if (n <= 4)
		{
			less_4(n, str);
		}
		else
		{
			more_4(n, str);
		}
	}
	return 0;
}