// 旋转排序数组查找值
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool search(vector<int>& nums, int target) {
    int l=0,r=nums.size()-1,mid;
    while(l<=r){
        mid = (l+r)>>1;
        if(nums[mid]==target){
            return true;
        }
        // 碰到l跟mid一样大的时候，l++防止不能判断是左边有序还是右边有序
        if(nums[l] == nums[mid]){
            l++;
            continue;
        }
        // 如果前半段有序
        if(nums[l]<=nums[mid]){
            // 如果前半段有序，且目标值小于mid，说明就在前半段的为值
            if(nums[mid]<target){
                l = mid+1;
            }
            // target就说比mid小，左边还是有序的,那么target在左边有点都有可能
            else{
                // 如果左边最小的都比tar大，说明在右边
                if(nums[l]>target){
                    l = mid+1;
                }
                // 反之在左边
                else{
                    r = mid-1;
                }
            } 
            
        }
        // 后半段有序
        else{
            // 如果后半段有序，那么target比mid小就好说只能在mid左边，如果mid位置的值比target大那就左右都可能需要判断
            if(nums[mid]>target){
                r = mid-1;
            }
            // 如果mid位置的值小于tar
            else{
                // 如果左边最小的还大于target，那就肯定在右边
                if(nums[l]>target){
                    l = mid+1;
                }
                else{
                    r = mid -1;
                }
            }
        }
        
    }
    return false;
}