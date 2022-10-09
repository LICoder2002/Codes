//6 �����������
//ĳ������n����������ҵ����m̨��ͬ�Ļ������мӹ�������ҵi����ļӹ�ʱ��Ϊti���κ���ҵ�ڱ�����ʱ������
//�ϣ�Ҳ���ܽ��в�ִ����ֳ����������дһ���������n����ҵ��m̨�����ӹ���������ʱ��
//����
//��һ��T��1 < T < 100)��ʾ��T��������ݡ�ÿ��������ݵĵ�һ�зֱ�������n��m��1 <= n <= 10000��
//	1 <= m <= 100������������һ����n������ti��1 <= t <= 100)��
//	���
//		��������ʱ��

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(const int& x, const int& y)
{
	return x > y;
}

int findMax(vector<int>& machines)
{
	int Max = machines[0];
	for (int i = 1; i < machines.size(); ++i)
	{
		Max = max(Max, machines[i]);
	}
	return Max;
}

int getTime(vector<int>& taskTime, vector<int>& machines)
{
	sort(taskTime.begin(), taskTime.end(), greater<int>());

	int taskNum = taskTime.size();
	int machineNum = machines.size();

	if (taskNum < machineNum)
		return taskTime[0];
	// Ϊÿһ����ҵѡ�����
	for(int i = 0; i < taskNum; ++i)
	{
		//�ҳ����Ƚ����Ļ���
		int finish = 0;
		int machineTime = machines[finish];
		for (int j = 1; j < machineNum; ++j)
		{
			if (machineTime > machines[j])
			{
				finish = j;
				machineTime = machines[j];
			}
		}
		
		machines[finish] += taskTime[i];
	}

	return findMax(machines);
}
//
//int main()
//{
//	int n = 0, m = 0;
//	cout << "�����������ͻ�����" << endl;
//	cin >> n >> m;
//	vector<int> taskTime(n);
//	vector<int> machines(m, 0);
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> taskTime[i];
//	}
//
//	int res = getTime(taskTime, machines);
//
//	cout << "��С����ʱ��: " << res << endl;
//}