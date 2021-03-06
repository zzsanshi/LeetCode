#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
// great -> 小根堆 -> 剩下的都是大的
class paircomp{
public:
    bool operator()(const pair<int,int> l,const pair<int,int> r){
        return l.second>r.second;
    }
};
// 12 ms  13.3 MB
vector<int> topKFrequent(vector<int>& nums, int k) {
    // key是数值，value是出现的频次
    unordered_map<int,int> occur;
    for(auto v:nums){
        occur[v]++;
    }
    // 使用堆排序或者快速查找+二分的思路（215题这两种思路都有）
    // 到这一步就回到了求前k个的问题了 只不过结构不同
    priority_queue<pair<int,int>,vector<pair<int,int>>,paircomp> pq;
    
    for(auto it=occur.begin();it!=occur.end();it++){
        pq.emplace(*it);
        if(pq.size()>k){
            pq.pop();
        }
    }
    vector<int> out(k);
    for(int i=k-1;i>=0;i--){
        out[i] = pq.top().first;
        pq.pop();
    }
    return out;
}