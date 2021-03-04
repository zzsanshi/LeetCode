// 二分查找如果没有提前return 那么left指向大于目标点的第一个 right指向小于目标点的第一个
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
// 按照题的意思判断 在二分的基础上判断当tmpsum小于目标值时，后面的是不是大于目标值
// 4 ms 5.8 MB
int mySqrt_v1(int x)
{
    int l = 0, r = x;
    long tmpsum;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        tmpsum = (long)mid * mid;
        if (tmpsum == x)
        {
            return mid;
        }
        else if (tmpsum > x)
        {
            r = mid - 1;
        }
        else if (tmpsum+2*mid+1>x)
        {
            return mid;
        }else{
            l = mid + 1;
        }
    }
    return 0;
}
// 我的思路 在二分法循环结束后 如果没有提前return 那么left指向大于目标点的第一个 right指向小于目标点的第一个
// 0 ms 5.8mb
int mySqrt_v1(int x)
{
    int l = 0, r = x;
    long tmpsum;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        tmpsum = (long)mid * mid;
        if (tmpsum == x)
        {
            return mid;
        }
        else if (tmpsum > x)
        {
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return r;
}