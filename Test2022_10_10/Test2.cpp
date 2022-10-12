//给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。
//https://leetcode.cn/problems/non-overlapping-intervals/
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    struct cmp
    {
        bool operator()(vector<int>& v1, vector<int>& v2)
        {
            return v1[0] < v2[0];
        }
    };

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
        {
            return 0;
        }

        //按照起始时间升序排序
        sort(intervals.begin(), intervals.end(), cmp());

        int num = 0; 
        int i = 0;
        for (int j = 1; j < intervals.size(); ++j)
        {
            if (intervals[j][0] >= intervals[i][1])
            {
                //不冲突
                i = j;
            }
            else
            {
                if (intervals[j][1] < intervals[i][1])
                {
                    i = j;
                }
                ++num;
            }
        }
        return num;
    }
};