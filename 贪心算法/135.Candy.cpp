#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;

// 注意，这道题没有定义说相邻的变现一样的孩子要得到一样多的糖果
// 16 ms 17.4 MB
int candy_v1(vector<int> &ratings)
{
    // 每个孩子至少一个糖果
    vector<int> value(ratings.size(), 1);
    // 由于从左向右扫描时只能维护右边比左边大，那么就涉及i-1,所以就从1开始
    for (int i = 1; i < ratings.size(); i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            value[i] = value[i - 1] + 1;
        }
    }
    // 跟上面一样，从右向左扫描，维护右边比左边大
    for (int j = ratings.size() - 2; j >= 0; j--)
    {
        if (ratings[j] > ratings[j + 1])
            value[j] = max(value[j], value[j + 1] + 1);
    }
    return accumulate(value.begin(), value.end(), 0);
}
