//7 �ѡ��
//��n����Ҫ��ͬһ��ʹ��ͬһ�����ҵĻa1, a2, ��, an������ͬһʱ��ֻ����һ���ʹ�á�ÿ���a[i]����һ��
//��ʼʱ��s[i]�ͽ���ʱ��f[i]��һ����ѡ��󣬻a[i]��ռ�ݰ뿪ʱ������[s[i], f[i])�����[s[i], f[i])��[s[j], f[j])������
//����a[i]��a[j]������Ϳ��Ա���������һ�졣��ʹ�þ�����Ļ�ܲ���ͻ�ľ��е����������

//ÿ��ѡȡ����ʱ������Ļ�����Եõ����Ž⡣�����ַ���ѡ�񣬿���Ϊδ���Ż���¾����ܶ��ʱ�䡣����ͼ��ʾ�Ļ����S�����и������ս���ʱ�䵥����������

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(vector<int>& v1, vector<int>& v2)
{
	return v1[1] < v2[1];
}

int getNum(vector<vector<int>>& events)
{
	//���ս���ʱ���������
	sort(events.begin(), events.end(), cmp);
	
	int num = 1;
	int i = 0;

	for (int j = 1; j < events.size(); ++j)
	{
		//��һ�������ʼʱ�䲻С�ڵ�ǰ��Ľ���ʱ��
		if (events[j][0] >= events[i][1])
		{
			++num;
			i = j;
		}
	}

	return num;
}

//int main()
//{
//	vector<vector<int>> events{ {2, 5}, {3, 4}, {1, 6}, {5, 8}, {5, 7} , {3, 9}, {7, 10} };
//
//	int res = getNum(events);
//
//	cout << res << endl;
//	return 0;
//}

