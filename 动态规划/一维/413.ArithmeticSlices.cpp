// 如果一个数列至少有三个元素，并且任意两个相邻元素之差相同，则称该数列为等差数列。

// 例如，以下数列为等差数列:
// 1, 3, 5, 7, 9
// 7, 7, 7, 7
// 3, -1, -5, -9
// 三个连续的就叫一个等差数列 再多也行 求等差数组个数
// 有点像脑筋急转弯的题

#include <vector>
#include <array>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
// 4 ms 7.3 MB
// TODO dp思路
int numberOfArithmeticSlices(vector<int>& nums) {
    vector<int> dp(nums.size(),0);
    for(int i=2;i<nums.size();i++){
        if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
            dp[i] = dp[i-1]+1;
        }
    }
    int sum=0;
    for(auto n:dp){
        sum+=n;
    }
    return sum;
}