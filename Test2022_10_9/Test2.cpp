//6 多机调度问题
//某工厂有n个独立的作业，由m台相同的机器进行加工处理。作业i所需的加工时间为ti，任何作业在被处理时不能中
//断，也不能进行拆分处理。现厂长请你给他写一个程序：算出n个作业由m台机器加工处理的最短时间
//输入
//第一行T（1 < T < 100)表示有T组测试数据。每组测试数据的第一行分别是整数n，m（1 <= n <= 10000，
//	1 <= m <= 100），接下来的一行是n个整数ti（1 <= t <= 100)。
//	输出
//		所需的最短时间

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
	// 为每一个作业选择机器
	for(int i = 0; i < taskNum; ++i)
	{
		//找出最先结束的机器
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
//	cout << "输入任务数和机器数" << endl;
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
//	cout << "最小结束时间: " << res << endl;
//}