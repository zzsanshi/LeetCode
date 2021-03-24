#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
// HOT
vector<int> getLeastNumbers(vector<int>& arr, int k) {

    if(k==0) return {};
    // 大根堆
    priority_queue<int,vector<int>,less<int>> bigheap;
    int i=0;
    for(;i<k;i++){
        bigheap.emplace(arr[i]);
    }
    for(;i<arr.size();i++){
        if(arr[i]<bigheap.top()){
            bigheap.pop();
            bigheap.emplace(arr[i]);
        }
    }
    vector<int> res;
    for(i=0;i<k;i++){
        res.emplace_back(bigheap.top());
        bigheap.pop();
    }
    return res;
}
int main(){
    vector<int> a{0,0,02,0,5};
    getLeastNumbers(a,0);
}