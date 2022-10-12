//7 活动选择
//有n个需要在同一天使用同一个教室的活动a1, a2, …, an，教室同一时刻只能由一个活动使用。每个活动a[i]都有一个
//开始时间s[i]和结束时间f[i]。一旦被选择后，活动a[i]就占据半开时间区间[s[i], f[i])。如果[s[i], f[i])和[s[j], f[j])互不重
//叠，a[i]和a[j]两个活动就可以被安排在这一天。求使得尽量多的活动能不冲突的举行的最大数量。

//每次选取结束时间最早的活动，可以得到最优解。按这种方法选择，可以为未安排活动留下尽可能多的时间。如下图所示的活动集合S，其中各项活动按照结束时间单调递增排序。

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
	//按照结束时间递增排序
	sort(events.begin(), events.end(), cmp);
	
	int num = 1;
	int i = 0;

	for (int j = 1; j < events.size(); ++j)
	{
		//下一个活动的起始时间不小于当前活动的结束时间
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

