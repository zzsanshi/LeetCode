#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

// 由于本题已经预先有序，所以使用双指针的策略，左边扫面右边扫描
vector<int> twoSum_v1(vector<int> &numbers, int target)
{
    auto l = numbers.begin();
    auto r = numbers.end() - 1;
    while (l != r)
    {
        // 超过预期，说明右面的值没人配合，右指针左移
        if (*l + *r > target)
        {
            r--;
        }
        // 同理，左指针右移
        else if (*l + *r < target)
        {
            l++;
        }
        else
        {
            return vector<int>{int(distance(numbers.begin(), l)) + 1, int(distance(numbers.begin(), r)) + 1};
        }
    }
    return {};
}

// 本体同样可以适用哈希表来实现，每次扫描到目标的时候都先匹配有没有跟自己合适的节点，若存在就一切顺利，否则继续扫描
vector<int> twoSum(vector<int> &numbers, int target)
{
    unordered_map<int, int> m{};
    for (int i = 0; i < numbers.size(); i++)
    {
        if (m.find(target - numbers[i]) != m.end())
        {
            return {m[target - numbers[i]] + 1, i + 1};
        }
        // 这里之所以先判断，再加入本次元素，是为了防止本次扫描的元素*2==target
        else
        {
            m[numbers[i]] = i;
        }
    }
    return {};
}