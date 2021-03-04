// 查找指定元素第一次与最后一次出现的位置
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
// 先搜左边界，再搜右边界 这个版本更好理解
// 8 ms 13.4 MB
vector<int> searchRange_v1(const vector<int>& nums, int target) {
    int l=0,r=nums.size()-1;
    int mid;
    while(l<=r){
        mid = (l+r)>>1;
        // 搜索左边界就是找到目标点时把右指针指过去，因为这个结构没有return出口，所以left一定会大于right指向tar，除非不存在tar
        if(nums[mid]==target){
            r = mid -1;
        }else if (nums[mid]>target)
        {
            r = mid -1;
        }else{
            l = mid + 1;
        }
    }
    // 注意这个顺序不能搞错，要先判断位置对不对，然后才能检查这个位置存的对不对。如果找不到左边界，那也不用搜索右边界
    if(l>=nums.size()||nums[l]!=target)
        return {-1,-1};
    int tarleft = l;
    // 搜索右端点
    l=0,r=nums.size()-1;
    while(l<=r){
        mid = (l+r)>>1;
        if(nums[mid]==target){
            l = mid + 1;
        }else if (nums[mid]>target)
        {
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return {tarleft,r};
}
// 压缩判断条件
// 8 ms 13.1 MB
vector<int> searchRange(const vector<int>& nums, int target) {
    int l=0,r=nums.size()-1;
    int mid;
    while(l<=r){
        mid = (l+r)>>1;
        if(nums[mid]<target){
            l = mid + 1;
        }else{
            r = mid -1;
        }
    }
    if(l>=nums.size()||nums[l]!=target)
        return {-1,-1};
    int tarleft = l;
    l=0,r=nums.size()-1;
    while(l<=r){
        mid = (l+r)>>1;
        if (nums[mid]>target)
        {
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return {tarleft,r};
}
int main(){
    cout<<searchRange({5,7,7,8,8,10},8)[0];
}