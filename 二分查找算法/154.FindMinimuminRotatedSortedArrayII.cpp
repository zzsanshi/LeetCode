// 旋转数组求最小值，感觉比旋转数组查找简单多了
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
// 8 ms 11.9 MB
int findMin(const vector<int>& nums) {
        int l=0,r=nums.size()-1,mid;
        if(nums[l]<nums[r]) return nums[l];
        while(l<=r){
            mid = (l+r)>>1;
            if (l > 0 && nums[l] < nums[l - 1]) {
                return nums[l];
            }
            // mid在第一个数组中
            if(nums[mid]>nums[l]){
                l = mid+1;
            }
            // mid在第二个数组中，我们求得就是这个数组的头 所以不能错过去
            else if (nums[mid]<nums[l])
            {
                r = mid;
            }
            // mid==l,丢掉l
            else{
                l++;
            }
        }
        return nums[r];
    }
int main(){
    cout<<findMin({10,1,10,10,10});
}