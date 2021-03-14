#include<vector>
#include<iostream>
#include<stack>
#include<array>
using namespace std;

vector<string> &vector2string(vector<int> &queens,vector<string> &vs,int n){
    for(int i=0;i<n;i++){
        string s = string(n,'.');
        s[queens[i]] = 'Q';
        vs.push_back(s);
    }
    return vs;
}
// 	8 ms	7.7 MB
// clo：竖线是否存在  l左斜，r右斜，out：输出数组，搜索xindex坐标
void backtrack(vector<bool> &clo,vector<bool> &l,vector<bool> &r,vector<vector<string>> &out,int xindex,vector<int> &queens){
    // 如果这里采用先判断后放入的策略，调用者就需要使用多点dfs的策略，太麻烦了
    int n = clo.size();
    if(xindex == n){
        // 搜索完了
        vector<string> board;
        out.emplace_back(vector2string(queens,board,n));
    }
    // 搜索 （xindex，i）位置
    for(int i=0;i<n;i++){
        // 这里要判断三个坐标 clo l r
        int lvalue = xindex+i;
        int rvalue = i-xindex+(n-1);
        if(clo[i]||l[lvalue]||r[rvalue]){
            continue;
        }
        clo[i] = true;
        l[lvalue] = true;
        r[rvalue] = true;
        queens[xindex] = i;
        backtrack(clo,l,r,out,xindex+1,queens);
        clo[i] = false;
        l[lvalue] = false;
        r[rvalue] = false;
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<bool> column(n,false);
    vector<bool> l(2*n-1,false);
    vector<bool> r(2*n-1,false);
    vector<int> queens(n,0);
    vector<vector<string>> out;
    backtrack(column,l,r,out,0,queens);
    return out;
}
int main(){
    solveNQueens(4);
}