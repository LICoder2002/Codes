//���ַ����е�һ��ֻ����һ�ε��ַ�
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string str;
	cin >> str;
	
	vector<int> count(128);

	for (auto ch : str)
	{
		count[ch]++;
	}

	for (auto ch : str)
	{
		if (count[ch] == 1)
		{
			cout << ch << endl;
			break;
		}
	}

	return 0;
}