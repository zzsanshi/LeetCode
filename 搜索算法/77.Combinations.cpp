#include<vector>
#include<iostream>
#include<stack>
#include<deque>
using namespace std;
// 8 ms 17.6 MB
void backtrack_v1(int n,int k,vector<vector<int>> &out,int idx,vector<int> &sk){
    if(sk.size()==k){
        out.emplace_back(sk);
        return;
    }
    // 判断不可能取得够得提前退出
    else if(sk.size()+(n-idx+1)<k) return;
    else{
        sk.emplace_back(idx);
        backtrack_v1(n,k,out,idx+1,sk);
        sk.pop_back();
        backtrack_v1(n,k,out,idx+1,sk);
    }
}
// 在版本1得基础上继续剪枝 当判断后面的只有都要才能满足的时候就不进行各种试探了,也就不会出现拿到最后不够拿得情况
// TODO

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> out;
    vector<int> sk;
    backtrack_v1(n,k,out,1,sk);
    return out;
}

int main(){

}