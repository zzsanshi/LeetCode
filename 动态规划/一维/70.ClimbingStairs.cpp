// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

// 注意：给定 n 是一个正整数。

#include <vector>
#include <array>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
// 使用动态规划的思路保存所有的中间结果
// 0ms 6.1mb;
int climbStairs(int n) {
    vector<int> dp(n+1,1);
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// 减少变量的使用
int climbStairs(int n) {
    long l=1,r=2,tmp;
    for(int i=2;i<=n;i++){
        tmp = l+r;
        l = r;
        r = tmp;
    }
    return l;
}