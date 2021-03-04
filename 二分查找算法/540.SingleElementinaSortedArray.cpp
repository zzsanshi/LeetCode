// 查找唯一只出现过一次的值
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// 如果存在一个属只出现过一次，那么这个数列是个奇数数列 0 1 2 3 4
// 4 ms 10.7 MB
int singleNonDuplicate(vector<int>& nums) {
    int l=0,r=nums.size()-1,mid;
    while(l<r){
        mid = (l+r)>>1;
        if(mid%2) mid--;
        if(nums[mid]==nums[mid+1]) l = mid+2;
        else r = mid;
    }
    return nums[r];
}