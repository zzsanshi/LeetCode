// 回溯法:是深度优先搜索有好多种解的情况,这样后面的解可以有效利用
#include<vector>
#include<iostream>
#include<stack>
#include<array>
using namespace std;
// 4 ms  7.4 MB
void backtrack(vector<int>& nums,vector<vector<int>> &out,int swapidx){
    if(swapidx==nums.size()-1){
        out.emplace_back(nums);
        return;
    }
    // 这里从自己开始就是为了保护自己不换也是一种可能性
    for(int i=swapidx;i<nums.size();i++){
        swap(nums[swapidx],nums[i]);
        backtrack(nums,out,swapidx+1);
        swap(nums[i],nums[swapidx]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> out;
    backtrack(nums,out,0);
    return out;
}
