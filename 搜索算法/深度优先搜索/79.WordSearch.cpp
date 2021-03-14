#include<vector>
#include<iostream>
#include<stack>
#include<deque>
using namespace std;

vector<vector<int>> dir{{-1,0},{1,0},{0,1},{0,-1}};
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

// 去除标记数组，利用char只是用了7个比特 用另一个比特存东西
// 184 ms	10.6MB
void backtrack(vector<vector<char>>& board,string &word,int idx,int i,int j,bool &has){


    if(i<0||has||i>=board.size()||j<0||j>=board[0].size()||board[i][j]!=word[idx]){
        return;
    }
    if(idx== word.size()-1){
        has = true;
        return;
    }
    board[i][j] ^=0x80;

    backtrack(board,word,idx+1,i+1,j,has);
    backtrack(board,word,idx+1,i-1,j,has);
    backtrack(board,word,idx+1,i,j+1,has);
    backtrack(board,word,idx+1,i,j-1,has);

    board[i][j] ^=0x80;
}
bool exist(vector<vector<char>>& board, string word) {
    bool has = false;
    int m = board.size(), n = board[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){   
            backtrack(board,word,0,i,j,has);
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