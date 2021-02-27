#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;

// 考虑到一个区间如果写一个判断是不是向相交的然后用类似背包的方式做，感觉效率不高，需要先定下一头
// 16ms 9mb
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    if (intervals.size() == 0)
        return 0;
    sort(intervals.begin(), intervals.end(), [](vector<int> &x, vector<int> &y) {
        return x[0] < y[0];
    });
    int flag = intervals[0][1];
    int count = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        // 发生碰撞，保留结尾小的那个,count不变，修正flag
        if (intervals[i][0] < flag)
        {
            flag = min(flag, intervals[i][1]);
            count++;
        }
        else
        {
            
            flag = intervals[i][1];
        }
    }
    return count;
}