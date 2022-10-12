//牛客网——MP3光标位置 https://www.nowcoder.com/questionTerminal/eaf5b886bd6645dd9cfb5406f3753e15?toCommentId=14643937

#include<iostream>
#include<string>
using namespace std;

void less_4(int n, string& str)
{
	int cur = 1; //初始位置
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
	int cur = 1;//初始位置
	int pagestart = 1;//页首

	for (auto ch : str)
	{
		if (ch == 'U')
		{
			if (cur == 1 && pagestart == 1)//第一首，页首
			{
				cur = n;
				pagestart = n - 3;
			}
			else if (cur == pagestart)//非第一首且为页首
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