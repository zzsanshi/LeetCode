#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// HOT
// 本以为结合快速排序与二分的思路应该可以一步到位，结果差太远
// 48 ms 9.8 MB
// 快速排序用来确定一个元素位置
int Partition(vector<int>& nums,int left,int right){
    // 加上两行随机后性能提升明显，这测试用例坏的很啊 8 ms 9.6 MB
    int keyLoc = left + rand() % (right - left);
    swap(nums[keyLoc], nums[left]);

    int temp = nums[left];
    while(left<right){
        while(left<right&&nums[right]>=temp) right--;
        nums[left] = nums[right];
        while(left<right&&nums[left]<=temp) left++;
        nums[right] = nums[left];
    }
    nums[left] = temp;
    return left;
}

void QuickSortK(vector<int>& nums,int left,int right,int k){
    if(left<right){
        // mid是已经位置确定的元素，这里不用快排都进行排序，使用二分的思路，在乱序数组中用Partition定位中间值
        int mid = Partition(nums,left,right);
        if(mid==k) return;
        else if(mid>k){
            QuickSortK(nums,left,mid-1,k);
        }else{
            QuickSortK(nums,mid+1,right,k);
        }
    }
}

int findKthLargest_v0(vector<int>& nums, int k) {
    int l = nums.size()-1;
    QuickSortK(nums,0,l,l-k+1);
    return nums[nums.size()-k];
}
// 使用小根堆的方式 8 ms 9.9 MB
int findKthLargest(vector<int>& nums, int k) {
    int len = nums.size();
    // 创建小根堆，小根堆中小的在上面，维护一个k大小的小根堆，扔掉更小的，那么小根堆顶就是保存的第k大的数
    priority_queue<int,vector<int>,greater<int>> min_heap;
    int i=0;
    for(;i<k;i++) min_heap.emplace(nums[i]);
    for(;i<len;i++){
        if(nums[i]>min_heap.top()){
            // 这里能确定nums[i]比堆顶大，所以可以先把对顶丢了，再加入nums[i] 这样快一点
            min_heap.pop();
            min_heap.emplace(nums[i]);
           
        }
    }
    return min_heap.top();
}


int main(){
    vector<int > arr{7,6,5,4,3,2,1};
    cout<<findKthLargest(arr,5);
}