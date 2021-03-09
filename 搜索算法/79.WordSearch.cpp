#include<vector>
#include<iostream>
#include<stack>
#include<deque>
using namespace std;

vector<vector<int>> dir{{-1,0},{1,0},{0,1},{0,-1}};
// i j 的下一步要匹配word[idx] 本方案超时
void backtrack_v1(vector<vector<char>>& board,string &word,vector<vector<bool>> &flag,int idx,int i,int j){
    if(idx>= word.size()){
        has = true;
        return;
    }
    for(auto d:dir){
        int x = i+d[0];
        int y = j+d[1];
        if(x>=0&&x<board.size()&&y>=0&&y<board[0].size()&&board[x][y]==word[idx]&&!flag[x][y]){
            flag[x][y] = true;
            backtrack_v1(board,word,flag,idx+1,x,y);
            flag[x][y] = false;
        }
    }
}
bool exist_v1(vector<vector<char>>& board, string word) {
    vector<vector<bool>> flag(board.size(),vector<bool>(board[0].size(),false));
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]==word[0]){
                flag[i][j] = true;
                backtrack(board,word,flag,1,i,j);
                flag[i][j] = false;
                if(has){
                    return true;
                }
            }
        }
    }
    // backtrack(board,word,flag,0);
    return false;
}
// 优化条件判断
// 当前idx需要判断在i j上合不合适 合适再给标记访问
// 236ms 11mb 勉强过了
void backtrack(vector<vector<char>>& board,string &word,vector<vector<bool>> &flag,int idx,int i,int j,bool &has){


    if(i<0||has||i>=board.size()||j<0||j>=board[0].size()||flag[i][j]||board[i][j]!=word[idx]){
        return;
    }
    if(idx== word.size()-1){
        has = true;
        return;
    }
    flag[i][j] = true;

    backtrack(board,word,flag,idx+1,i+1,j,has);
    backtrack(board,word,flag,idx+1,i-1,j,has);
    backtrack(board,word,flag,idx+1,i,j+1,has);
    backtrack(board,word,flag,idx+1,i,j-1,has);

    flag[i][j] = false;
}
bool exist(vector<vector<char>>& board, string word) {
    bool has = false;
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> flag(m,vector<bool>(n,false));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){   
            backtrack(board,word,flag,0,i,j,has);
            if(has){
                return true;
            }
    }
    }
    // backtrack(board,word,flag,0);
    return has;
}

int main(){
    vector<vector<char>> t{{'C','A','A'},{'A','A','A'},{'B','C','D'}};
    string s = "AAB";
    cout<<exist(t,s);
}