#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
// 方便进行调试
template<typename T>
ostream& operator<<(ostream &os,vector<T> t){
    auto s=t.begin(),e=t.end();
    while(s!=e){
        os<<*s<<" ";
        s++;
    }
    return os;
}

// 单调栈寻找下一个更大的元素
vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> sk;
    int len = nums.size();
    vector<int> out(len,-1);
    for(int i=0;i<len*2;i++){
        while(!sk.empty()&&nums[sk.top()]<nums[i%len]){
            out[sk.top()] = nums[i%len];
            sk.pop();
        }
        sk.push(i%len);
    }
    return out;
}

int main(){
    vector<int> nums{1,2,1};
    cout<<nextGreaterElements(nums)<<endl;
}